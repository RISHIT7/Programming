#include <iostream>

int main(int argc, char* argv[])
{
    // Checking if all the inputs are preesent
    if (argc != 8)
    {
        std::cerr << "Usage: \n./cacheSim <no_sets> <no_blocks_per_set> <block_size> <write_policy> <replacement_policy> < <trace_file>" << std::endl;
    }

    int setNum = std::stoi(argv[1]);
    int blocksPerSet = std::stoi(argv[2]);
    int blockSize = std::stoi(argv[3]);
    std::string writePolicy = argv[4];
    std::string replacementPolicy = argv[5];
    std::string traceFile = argv[6];


    return 0;
}