#include "../include/Cache.hpp"

MemoryAccess stringToMemAccess(const std::string trace)
{
    MemoryAccess access;
    access.loadStore = trace[0];
    access.address = std::stoull(trace.substr(2, 10), nullptr, 16);

    return access;
}

void Cache::updateLRU(int index, int blockIndex)
{
    unsigned long long int maxLRUCounter = 0;

    for (unsigned long long i = 0; i < blocksPerSet; i++)
    {
        if (i != maxLRUCounter && cache[index][i].lruPosition > maxLRUCounter)
        {
            maxLRUCounter = cache[index][i].lruPosition;
        }
    }

    cache[index][blockIndex].lruPosition = maxLRUCounter + 1;
}

void Cache::updateFIFO(int index, int blockIndex, long long int miss)
{
    cache[index][blockIndex].fifoCount = miss;
}

void Cache::memoryAccess(const MemoryAccess access)
{
    unsigned long long int cacheSize = setsNum * blocksPerSet * blockSize;
    // bitwise AND with address will give the indexBits
    unsigned long long int indexMask = (cacheSize / (blocksPerSet * blockSize)) - 1;
    unsigned long long int index = (access.address / blockSize) & indexMask;
    unsigned long long int tag = (access.address / (blockSize * (indexMask + 1)));

    // result variables
    long long int hit = 0, miss = 0, reads = 0, writes = 0, totalcycles = 0;

    // checking for access address in cache
    for (unsigned long long i = 0; i < blocksPerSet; i++)
    {
        if (cache[index][i].valid && tag == cache[index][i].tag)
        {
            // address found
            hit++;
            if (access.loadStore == "s")
            {
                // choosing whether write-back or write-through
                if (writeHitPolicy == "write-back")
                {
                    cache[index][i].dirty = true;
                }
                else
                {
                    writes++;
                }
            }

            if (replacementPolicy == "lru")
            {
                updateLRU(index, i);
            }
            return;
        }
    }

    miss++;
    reads++;

    int victimBlockIndex = -1;
    unsigned long long int minCounter = -1;

    // updating victim block index
    for (unsigned long long i = 0; i < blocksPerSet; i++)
    {
        unsigned long long int counter = cache[index][i].lruPosition;

        if (replacementPolicy == "fifo")
        {
            counter = cache[index][i].fifoCount;
        }

        if (counter < minCounter)
        {
            minCounter = counter;
            victimBlockIndex = i;
        }
    }

    if (access.loadStore == "s")
    {
        if (writeHitPolicy == "write-back")
        {
            if (cache[index][victimBlockIndex].dirty)
            {
                writes++;
            }
        }
        else
        {
            writes++;
        }
    }

    if (access.loadStore == "l" && writeHitPolicy == "write-back" && cache[index][victimBlockIndex].dirty && cache[index][victimBlockIndex].valid)
    {
        writes++;
    }

    cache[index][victimBlockIndex].valid = true;
    cache[index][victimBlockIndex].tag = tag;
    cache[index][victimBlockIndex].dirty = (access.loadStore == "s" && writeHitPolicy == "write-back");

    if (replacementPolicy == "lru")
    {
        updateLRU(index, victimBlockIndex);
    }
    else
    {
        updateFIFO(index, victimBlockIndex, miss);
    }
    std::cout << hit << " " << miss << "\n";
}

Cache::Cache(unsigned long long int sets_number, unsigned long long int blocks_per_set, unsigned long long int block_size, std::string write_hit_policy, std::string write_miss_policy, std::string replacement_policy)
{
    setsNum = sets_number;
    blocksPerSet = blocks_per_set;
    blockSize = block_size;

    writeHitPolicy = write_hit_policy;
    writeMissPolicy = write_miss_policy;
    replacementPolicy = replacement_policy;

    // initialise cache
    for (unsigned long long int i = 0; i < setsNum; i++)
    {
        std::vector<CacheConstruct> internal_cache(blocksPerSet);
        cache.push_back(internal_cache);
    }
}

void Cache::parseTrace(const std::string trace)
{
    MemoryAccess access = stringToMemAccess(trace);
    memoryAccess(access);
}

Cache::~Cache() {}