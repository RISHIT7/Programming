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
    int k;
    cin >> k;

    vector<vector<int>> a(k);

    rep(i, 0, k)
    {
        int size;
        cin >> size;

        a[i] = vector<int>(size);
        rep(j, 0, size)
        {
            cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0);

    priority_queue<pii, vii, greater<pii>> pq;
    rep(i, 0, k)
    {
        pii p;
        p.ff = a[i][0];
        p.ss = i;
        pq.push(p);
    }

    vi ans;

    while (!pq.empty())
    {
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.ff);

        if (idx[x.ss] + 1 < a[x.ss].size())
        {
            pii p;
            p.ff = a[x.ss][idx[x.ss] + 1];
            p.ss = x.ss;
            pq.push(p);
        }
        idx[x.ss] += 1;
    }

    rep(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}