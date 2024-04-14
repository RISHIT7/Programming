#include "../include/Cache.hpp"

MemoryAccess stringToMemAccess(const std::string trace)
{
    MemoryAccess access;
    access.readWrite = trace[0];
    access.address = trace.substr(4, 8);

    return access;
}

void memoryAccess(const MemoryAccess access)
{
    std::cout << access.readWrite << " " << access.address << "\n";
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
    for (unsigned long long int  i = 0; i < setsNum; i++)
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