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

bool Cache::read(MemoryAccess access, unsigned long long int indexMask)
{
    unsigned long long int index = (access.address / blockSize) & indexMask;
    unsigned long long int tag = (access.address / (blockSize * (indexMask + 1)));

    for (unsigned long long int i = 0; i < blocksPerSet; i++)
    {
        if (cache[index][i].valid && cache[index][i].tag == tag)
        {
            // Hit
            updateLRU(index, i);
            // updateFIFO(index, i);
            return true;
        }
    }

    // Miss
    if (writeMissPolicy == "write-allocate")
    {
        // write allocate
        for (unsigned long long int i = 0; i < blocksPerSet; i++)
        {
            if (!cache[index][i].valid)
            {
                // Found Empty
                cache[index][i].dirty = false;
                cache[index][i].valid = true;
                cache[index][i].tag = tag;
                cache[index][i].lruPosition = 0;
                cache[index][i].fifoCount = 0;
                updateLRU(index, i);

                // updateFIFO(index, i);
                break;
            }
        }
        // Did not find any empty positions
        
        // implement lru and fifo
        
        return false;
    }
    return false;
}

bool Cache::write(MemoryAccess access, unsigned long long int indexMask)
{
    unsigned long long int index = (access.address / blockSize) & indexMask;
    unsigned long long int tag = (access.address / (blockSize * (indexMask + 1)));

    for (unsigned long long int i = 0; i < blocksPerSet; i++)
    {
        if (cache[index][i].valid && cache[index][i].tag == tag)
        {
            // Hit
            if (writeHitPolicy == "write-back")
            {
                // setting the dirty bit to true for write-back
                cache[index][i].dirty = true;
            }
            updateLRU(index, i);
            // updateFIFO(index, i);

            return true;
        }
    }

    // Miss
    if (writeMissPolicy == "write-allocate")
    {
        // write allocate
        for (unsigned long long int i = 0; i < blocksPerSet; i++)
        {
            if (!cache[index][i].valid)
            {
                // Found Empty
                cache[index][i].dirty = false;
                cache[index][i].valid = true;
                cache[index][i].tag = tag;
                cache[index][i].lruPosition = 0;
                cache[index][i].fifoCount = 0;
                updateLRU(index, i);

                // updateFIFO(index, i);
                break;
            }
        }
        // Did not find any empty positions
        
        // implement lru and fifo
        
        return false;
    }
    return false;
}

void Cache::memoryAccess()
{
    unsigned long long int cacheSize = setsNum * blocksPerSet * blockSize;
    // bitwise AND with address will give the indexBits
    unsigned long long int indexMask = (cacheSize / (blocksPerSet * blockSize)) - 1;

    // result variables
    long long int loads = 0, stores = 0, totalCycles = 0;
    long long int storeHit = 0, loadHit = 0, storeMiss = 0, loadMiss = 0;

    for (auto access : accessList)
    {
        std::cout << access.loadStore << " " << access.address << std::endl;
    }

    for (MemoryAccess access : accessList)
    {
        if (access.loadStore == "l")
        {
            loads++;
            if (read(access, indexMask))
            {
                // load hit
                loadHit++;
                totalCycles += 1;
            }
            else
            {
                // load Miss
                loadMiss++;
                if (writeMissPolicy == "write-allocate")
                {
                    totalCycles += 101;
                }
                else
                {
                    totalCycles += 100;
                }
            }
        }
        else
        {
            stores++;
            if (write(access, indexMask))
            {
                // store hit
                storeHit++;
                if (writeHitPolicy == "write-back")
                {
                    // since data updated in the cache
                    totalCycles += 1;
                }
                else
                {
                    // considering both updates in the cache and main memory
                    totalCycles += 101;
                }
            }
            else
            {
                storeMiss++;
                if (writeMissPolicy == "write-allocate")
                {
                    totalCycles += 101;
                }
                else
                {
                    totalCycles += 100;
                }
            }
        }
    }
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Total Loads: " << loads << "\nTotal Stores: " << stores << "\nLoad Hits: " << loadHit << "\nLoad Misses: " << loadMiss << "\nStore Hits: " << storeHit << "\nStore Misses: " << storeMiss << "\nTotal Cycles: " << totalCycles << "\n";
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
    accessList.push_back(access);
}

Cache::~Cache() {}