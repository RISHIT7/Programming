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

const int N = 1e3 + 2, MOD = 1e9 + 7;
int dp[N][N];

// int Knapsack(int n, int w, vi wt, vi val)
// {
//     if (w < 0)
//     {
//         return 0;
//     }

//     if (n <= 0)
//     {
//         return 0;
//     }
    
//     if (dp[n][w] != -1)
//     {
//         return dp[n][w];
//     }

//     if (wt[n - 1] > w)
//     {
//         dp[n][w] = Knapsack(n - 1, w, wt, val);
//     }

//     dp[n][w] = max(Knapsack(n - 1, w, wt, val), Knapsack(n - 1, w - wt[n - 1], wt, val) + val[n - 1]);

//     return dp[n][w];
// }

// signed main()
// {

//     rep(i, 0, N)
//     {
//         rep(j, 0, N)
//         {
//             dp[i][j] = -1;
//         }
//     }

//     int n;
//     cin >> n;

//     vi wt(n), val(n);

//     rep(i, 0, n)
//     {
//         cin >> wt[i];
//     }

//     rep(i, 0, n)
//     {
//         cin >> val[i];
//     }

//     int w;
//     cin >> w;

//     cout << Knapsack(n, w, wt, val) << endl;
//     return 0;
// }