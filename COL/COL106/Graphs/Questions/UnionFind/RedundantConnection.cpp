#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// #define int long long
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define print_any(vec)     \
    for (auto value : vec) \
        cout << value << " ";
#define next_line cout << endl;

const int N = 1e5 + 2, MOD = 1e9 + 7;

signed main()
{
    int n = 5;
    vector<pair<int, int>> ans;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 3}, {1, 5}, {2, 5}};
    map<int, int> parents;
    for (auto i : edges)
    {
        int a = i.first;
        int b = i.second;

        if (a > b)
        {
            int temp = a;
            a = b;
            b = a;
        }

        if (parents.count(a) == 0)
        {
            parents[b] = a;
        }
        else if (parents.count(a) != 0)
        {
            if (parents[b] == parents[a])
            {
                ans.push_back({a, b});
            }
            else
            {
                parents[b] = parents[a];
            }
        }
    }

    for (auto val : ans)
    {
        cout << "[" << val.first << "," << val.second << "]";
    }
    cout << "\n";

    // set<int> count;
    // for (map<int, int>::iterator i = parents.begin(); i != parents.end(); i++)
    // {
    //     count.insert(i->second);
    // }
    // cout << count.size() << endl;

    return 0;
}