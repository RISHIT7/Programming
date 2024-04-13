#include "../include/Cache.hpp"

Cache::Cache(int sets_number, int blocks_per_set, int block_size, std::string write_hit_policy, std::string write_miss_policy, std::string replacement_policy)
{
    setsNum = sets_number;
    blocksPerSet = blocks_per_set;
    blockSize = block_size;

    writeHitPolicy = write_hit_policy;
    writeMissPolicy = write_miss_policy;
    replacementPolicy = replacement_policy;

    cacheIsValid = {};
}

void Cache::accessMemory(const MemoryAccess &access)
{
    // a lot of jargan
}

Cache::~Cache(){}