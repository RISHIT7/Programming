#include <iostream>
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
// int dp[N];

// int lis(vi &a, int n)
// {
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     dp[n] = 1; // single element is also an lis

//     rep(i, 0, n)
//     {
//         if (a[n] > a[i])
//         {
//             dp[n] = max(d[n], 1 + list(a, i));
//         }
//     }

//     return dp[n];
// }

// signed main()
// {
//     rep(i, 0, N)
//     {
//         dp[i] = -1;
//     }

//     int n;
//     cin >> n;

//     vi a(n);
//     rep(i, 0, n)
//     {
//         cin >> a[i];
//     }

//     cout << lis(a, n - 1) << endl;
//     return 0;
// }

signed main()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vi dp(n, 1);

    int ans = 0;
    rep(i, 1, n)
    {
        rep(j, 0, i)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}