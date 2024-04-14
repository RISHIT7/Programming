#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>

struct MemoryAccess
{
    std::string readWrite;
    std::string address;
};

struct CacheConstruct
{
    bool valid;
    unsigned long long int tag;
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

    friend MemoryAccess stringToMemAccess(const std::string trace);
    friend void memoryAccess(const MemoryAccess access);
    
    std::vector<std::vector<CacheConstruct>> cache;

public:
    // Constructor
    Cache(unsigned long long int sets_number, unsigned long long int blocks_per_set, unsigned long long int block_size, std::string write_hit_policy, std::string write_miss_policy, std::string replacement_policy);

    // Access memory function
    void parseTrace(const std::string trace);

    // Destructor
    ~Cache();
};