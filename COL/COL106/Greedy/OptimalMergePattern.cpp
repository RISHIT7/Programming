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

bool compare(pii p1, pii p2)
{
    double v1 = (double)p1.ff / p1.ss;
    double v2 = (double)p2.ff / p2.ss;

    return v1 > v2;
}

signed main()
{
    int n;
    cin >> n;

    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    priority_queue<int, vi, greater<int>> minheap;
    rep(i, 0, n)
    {
        minheap.push(a[i]);
    }

    int ans = 0;

    while (minheap.size() > 1)
    {
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();

        ans += e1 + e2;
        minheap.push(e1 + e2);
    }

    cout << ans << endl;
    return 0;
}