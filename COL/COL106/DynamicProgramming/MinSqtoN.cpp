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

// int MinSquare(int n)
// {
//     if (n == 1 || n == 2 || n == 3 || n == 0)
//     {
//         return n;
//     }

//     if (dp[n] != MOD)
//     {
//         return dp[n];
//     }

//     for (int i = 1; i * i <= n; i++)
//     {
//         dp[n] = min(dp[n], 1 + MinSquare(n - i * i));
//     }

//     return dp[n];
// }

// signed main()
// {
//     int n;
//     cin >> n;

//     rep(i, 0, N)
//     {
//         dp[i] = MOD;
//     }

//     cout << MinSquare(n) << endl;
//     return 0;
// }

signed main()
{
    int n;
    cin >> n; 

    vi dp(n + 1, MOD);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 1; i * i <= n; i++)
    {
        for (int j = 0; i * i + j <= n; j++)
        {
            dp[i * i + j] = min(dp[i * i + j], 1 + dp[j]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}