#include <iostream>
#include <cctype>
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
        for (int k = 0; k <= input.size() - i.str.size(); k++)
        {
            if (i.str.compare(input.substr(k, i.str.size())) == 0)
            {
                ret.push_back({k, i.i});
                cout << k << " " << i.i <<  endl;
            }
        }
    }
    return ret;
}

int main()
{
    std::string input = "ashdffjssevenasgsfgonetwosixseveneight";

    vector<num_string> string_cache = string_match(input);

    return 0;
}
