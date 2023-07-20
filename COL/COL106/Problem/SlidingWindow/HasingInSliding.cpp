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
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define print_any(vec)     \
    for (auto value : vec) \
        cout << value << " ";
#define next_line cout << endl;

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    map<int, int> freq;

    rep(i, 0, n)
    {
        int presentSize = freq.size();

        if (freq[a[i]] == 0 && presentSize == k)
        {
            break;
        }
        freq[a[i]]++;
    }

    vii ans;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        if (it->ss != 0)
        {
            ans.push_back({it->ss, it->ff});
        }
    }
    sort(ans.begin(), ans.end(), greater<pii>());

    vii::iterator i;
    for (i = ans.begin(); i != ans.end(); i++)
    {
        cout << i->ss << " " << i->ff << endl;
    }

    return 0;
}