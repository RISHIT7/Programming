/*
MAPS

Insertion: O(logn)
Accessing: O(logn)
Deletion: O(logn)
Implemented using Red Black Trees

Unordered Maps
Insertionn: O(1) on avg
Acessing: O(1)
Deletion: O(n)
Implemented using Hash tables
*/

#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print_any(vec) for(auto value:vec)cout<<value<<" ";
#define next_line cout<<endl;

signed main()
{
    map<int, int> m;

    m[8] = 2;
    cout<<m[8]<<endl;

    return 0;
}