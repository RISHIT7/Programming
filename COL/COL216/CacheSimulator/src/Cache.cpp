#include "../include/Cache.hpp"

MemoryAccess stringToMemAccess(std::string trace)
{
    MemoryAccess access;
    access.readWrite = trace[0];
    access.address =  std::stoull(trace.substr(2, 10), nullptr, 16);

    return access;
}

Cache::Cache(int sets_number, int blocks_per_set, int block_size, std::string write_hit_policy, std::string write_miss_policy, std::string replacement_policy)
{
    setsNum = sets_number;
    blocksPerSet = blocks_per_set;
    blockSize = block_size;

    writeHitPolicy = write_hit_policy;
    writeMissPolicy = write_miss_policy;
    replacementPolicy = replacement_policy;

    cache = {};
}

void Cache::accessMemory(std::string trace)
{
    MemoryAccess access = stringToMemAccess(trace);
    std::cout << access.readWrite << " " << access.address << "\n";
}

Cache::~Cache() {}