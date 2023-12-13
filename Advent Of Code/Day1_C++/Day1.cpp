#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef struct
{
    int location;
    int value;
} num_string;

typedef struct
{
    string str;
    int i;
} lookup_t;

lookup_t gTable[] = {
    {string("zero"), 0},
    {string("one"), 1},
    {string("two"), 2},
    {string("three"), 3},
    {string("four"), 4},
    {string("five"), 5},
    {string("six"), 6},
    {string("seven"), 7},
    {string("eight"), 8},
    {string("nine"), 9},
};

vector<num_string> string_match(string input)
{
    vector<num_string> ret;
    for (auto i : gTable)
    {
        if (input.size() < i.str.size())
        {
            continue;
        }
        else
        {
            for (int k = 0; k <= input.size() - i.str.size(); k++)
            {
                if (i.str.compare(input.substr(k, i.str.size())) == 0)
                {
                    ret.push_back({k, i.i});
                }
            }
        }
    }
    return ret;
}

uint32_t match(string &slice)
{
    for (int i = 0; i < 9; i++)
    {
        if (!gTable[i].str.compare(slice))
        {
            return gTable[i].i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    if (!argv[1])
    {
        cerr << "Provide a file name!"
             << "\n";
        return 1;
    }
    ifstream inputFile;
    inputFile.open(argv[1]);

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file!"
             << "\n";
        return 1;
    }

    string line;
    uint32_t sum = 0;
    while (getline(inputFile, line))
    {
        uint32_t first_digit = -1;
        uint32_t second_digit = 0;
        int first_idx = 0;
        int second_idx = 0;
        vector<num_string> string_cache = string_match(line);

        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]) && first_digit == -1)
            {
                first_digit = (int)line[i] - 48;
                first_idx = i;
                second_digit = (int)line[i] - 48;
                second_idx = i;
            }
            else if (isdigit(line[i]))
            {
                second_digit = (int)line[i] - 48;
                second_idx = i;
            }
        }

        // check for the first digit
        for (auto i : string_cache)
        {
            if (first_idx > i.location)
            {
                first_idx = i.location;
                first_digit = i.value;
            }
        }

        // check for the second digit
        for (auto i : string_cache)
        {
            if (second_idx < i.location)
            {
                second_digit = i.value;
                second_idx = i.location;
            }
        }

        sum += ((10 * first_digit) + second_digit);
    }
    cout << sum << "\n";
    inputFile.close();

    return 0;
}