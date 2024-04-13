#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>

struct MemoryAccess
{
    std::string readWrite;
    unsigned long long address;
};

// Cache class
class Cache
{
private:
    unsigned long long int setsNum;
    unsigned long long int blocksPerSet;
    unsigned long long int blockSize;
    std::string writeHitPolicy;
    std::string writeMissPolicy;
    std::string replacementPolicy;

    friend MemoryAccess stringToMemAccess(std::string trace);
    
    std::vector<std::vector<MemoryAccess>> cache;

public:
    // Constructor
    Cache(int sets_number, int blocks_per_set, int block_size, std::string write_hit_policy, std::string write_miss_policy, std::string replacement_policy);

    
    // Access memory function
    void accessMemory(std::string trace);

    // Destructor
    ~Cache();
};