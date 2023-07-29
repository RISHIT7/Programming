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
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vii a(n);

        rep(i, 0, n)
        {
            cin >> a[i].ff >> a[i].ss;
        }

        int l, p;
        cin >> l >> p;

        rep(i, 0, n)
        {
            a[i].ff = l - a[i].ff;
        }

        sort(a.begin(), a.end());

        int ans = 0;
        int curr = p;

        priority_queue<int, vi> pq;
        bool flag = 0;
        rep(i, 0, n)
        {
            if (curr >= l)
            {
                break;
            }

            while (curr < a[i].ff)
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if (flag == 1)
            {
                break;
            }
            pq.push(a[i].ss);
        }

        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }

        while (!pq.empty() and curr < l)
        {
            curr += pq.top();
            pq.pop();
            ans++;
        }

        if (curr < l)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}