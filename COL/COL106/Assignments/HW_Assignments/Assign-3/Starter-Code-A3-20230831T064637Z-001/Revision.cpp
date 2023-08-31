#include <iostream>
#include <cmath>
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

struct Account
{
    std::string id;
    int balance;
};

signed main()
{
    vector<Account> bankstorage1d;
    Account *new_account = new Account();
    new_account->balance = 365514;
    new_account->id = "abcdef";
    bankstorage1d.push_back(*new_account);
    delete new_account;

    cout << "id is: " << bankstorage1d[0].id << "\nand the balance is: " << bankstorage1d[0].balance << endl;
    return 0;
}