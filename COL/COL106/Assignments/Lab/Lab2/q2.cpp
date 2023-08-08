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

// const int N = 1e5 + 2, MOD = 1e9 + 7;

// signed main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     rep(i, 0, n)
//     {
//         cin >> a[i];
//     }

//     rep(i, 0, n-1)
//     {
//         int ctr = i + 1;
//         rep(j, i + 1, n)
//         {
//             if (a[i] <= a[j])
//             {
//                 a[i] = a[j];
//                 break;
//             }
//             ctr++;
//         }
//         if (ctr == n)
//         {
//             cout << ctr << endl;
//             a[i] = -1;
//         }
//     }
//     a[n-1] = -1;
//     print_any(a);
//     return 0;
// }