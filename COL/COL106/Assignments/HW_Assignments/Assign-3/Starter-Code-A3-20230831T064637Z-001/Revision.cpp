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

void createAccount(std::string id, int count)
{
    Account *new_account = new Account();
    new_account->balance = count;
    new_account->id = id;

    int Hash_val = hash(id);

    vector<Account> temp;
    temp.push_back(*new_account);

    try
    {
        bankstorage2d[Hash_val].push_back(*new_account);
    }
    catch (std::runtime_error())
    {
        vector<Account> temp;
        temp.push_back(*new_account);
        bankstorage2d.insert(bankstorage2d.begin() + Hash_val, temp);
    }

    size++;

    delete new_account;
}


int hash_foo(string id)
{
    int p = 31;
    int hash = 0;
    int factor = 1;

    for (int i = 0; i < id.size(); i++)
    {
        hash += (id[i] - 'A' + 1) * factor;
        factor *= p;
    }

    return hash % (99991);
}

signed main()
{
    vector<vector<Account>> bankstorage2d(100000);
    // Account *init = new Account();
    // init->balance = 545161;
    // init->id = "abcdef";

    // int idx = hash_foo(init->id);
    // vector<Account> vec;
    // vec.push_back(*init);
    // bankstorage2d.insert(bankstorage2d.begin() + idx, vec);

    Account *new_account = new Account();
    new_account->balance = 365514;
    new_account->id = "abcdef";

    int Hash_val = hash_foo(new_account->id);

    try
    {
        bankstorage2d[Hash_val].push_back(*new_account);
    }
    catch (std::runtime_error())
    {
        vector<Account> temp;
        temp.push_back(*new_account);
        bankstorage2d.insert(bankstorage2d.begin() + Hash_val, temp);
    }

    // try
    // {
    //     bankstorage2d[Hash_val].push_back(*new_account);
    // }
    // catch (const std::exception &e)
    // {
    //     // nothing
    // }
    // vector<Account> temp;
    // temp.push_back(*new_account);
    // bankstorage2d.insert(bankstorage2d.begin() + Hash_val, temp);

    delete new_account;

    cout << "id is: " << bankstorage2d[Hash_val][0].id << "\nand the balance is: " << bankstorage2d[Hash_val][0].balance << endl;
    return 0;
}