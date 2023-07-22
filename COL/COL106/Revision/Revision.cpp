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

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> a(n);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        vector<ll> mult;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                mult.push_back((a[i]*a[j])/__gcd(a[i], a[j]));
            }
        }
        sort(mult.begin(), mult.end());
        rep(i, 0, mult.size()-1)
        {
            if (mult[i] == mult[i+1])
            {
                cout<<mult[i]<<endl;
                break;
            }
        }
    }
    return 0;
}