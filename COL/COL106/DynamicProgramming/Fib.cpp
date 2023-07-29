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

const int N = 1e5 + 2, MOD = 1e9 + 7;

// ll dp[N];

// int fib(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n == 1)
//     {
//         return 1;
//     }
//     if (n == 2)
//     {
//         return 1;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     dp[n] = fib(n - 1) + fib(n - 2);

//     return dp[n];
// }

// signed main()
// {
//     int n;
//     cin>>n;

//     rep(i, 0, N)
//     {
//         dp[i] = -1;
//     }

//     fib(n);
//     return 0;
// }

signed main()
{
    int n;
    cin >> n;

    vi dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    rep(i, 3, n + 1)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}