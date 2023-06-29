#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P
{
    int x, y;
    bool operator<(const P &p)
    {
        if (x != p.x)
            return x < p.x;
        else
            return y < p.y;
    }
};

int main()
{
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end());
    vector<pair<int, int>> a;
    a.push_back({1, 5});
    a.push_back({2, 3});
    a.push_back({1, 2});
    sort(a.begin(), a.end());
    // User defined structs
    return 0;
}