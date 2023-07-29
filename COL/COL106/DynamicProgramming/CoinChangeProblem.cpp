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
#define vvi vector<vector<int>>
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

const int N = 1e3 + 2;

void solve_iterative()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;

    vvi dp(m + 1, vi(x + 1, 0));
    dp[0][0] = 1;

    rep(i, 1, m + 1)
    {
        rep(j, 0, x + 1)
        {
            if (j - s[i - 1] >= 0)
            {
                dp[i][j] += dp[i][j - s[i - 1]];
                dp[i][j] += dp[i - 1][j];
            }
        }
    }

    cout << dp[m][x] << endl;
}

void iterative_optimized()
{
    int m;
    cin >> m;

    vi s(m);

    rep(i, 0, m)
    {
        cin >> s[i];
    }

    int x;
    cin >> x;

    vi dp(x + 1, 0);
    dp[0] = 1'

        rep(i, 0, m)
    {
        rep(j, 0, x + 1)
        {
            if (j - s[i] >= 0)
            {
                dp[i] += dp[j - s[i]];
            }
        }
    }

    cout << dp[x] << endl;
}

int dp[N][N];

int fun(vi &a, int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    if (n <= 0 && x > 0)
    {
        return 0;
    }
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }

    dp[n][x] = fun(a, n - 1, x) + fun(a, n, x - a[n - 1]);

    return dp[n][x];
}

signed main()
{
    int n;
    cin >> n;

    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            dp[i][j] = -1;
        }
    }

    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;

    cout << func(a, n, x) << endl;
    return 0;
}