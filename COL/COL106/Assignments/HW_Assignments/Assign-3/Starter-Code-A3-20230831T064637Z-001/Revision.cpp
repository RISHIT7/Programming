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

vector<vector<Account>> bankstorage2d(100000);
int S = 0;

int hash_foo(string id)
{
    int p = 31;
    long long int hash = 0;
    int factor = 1;

    for (int i = 0; i < id.size(); i++)
    {
        hash += (id[i] + 1) * factor;
        factor *= p;
    }

    return hash % (99991);
}

void createAccount(std::string id, int count)
{
    Account *new_account = new Account();
    new_account->balance = count;
    new_account->id = id;

    int Hash_val = hash_foo(id);

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

    S++;

    delete new_account;
}

void addTransaction(std::string id, int count) // to be tested, could be better implemented
{
    int Hash_val = hash_foo(id);
    vector<Account> temp;
    try
    {
        temp = bankstorage2d[Hash_val];
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].id == id)
            {
                bankstorage2d[Hash_val][i].balance += count;
                return;
            }
        }
    }
    catch (std::runtime_error())
    {
        createAccount(id, count);
        return;
    }

    createAccount(id, count);
    return;
}

int getBalance(std::string id)
{
    int Hash_val = hash_foo(id);
    vector<Account> temp;
    try
    {
        vector<Account> temp = bankstorage2d[Hash_val];
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].id == id)
            {
                return temp[i].balance;
            }
        }
    }
    catch (std::runtime_error())
    {
        return -1;
    }

    return -1;
}

bool deleteAccount(std::string id) // to be tested, does not include case when Has dne
{
    int Hash_val = hash_foo(id);
    vector<Account> temp;
    try
    {
        vector<Account> temp = bankstorage2d[Hash_val];
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].id == id)
            {
                S--;
                bankstorage2d[Hash_val].erase(temp.begin() + i);
                return true;
            }
        }
    }
    catch (std::runtime_error())
    {
        return -1;
    }

    return false;
}

signed main()
{
    createAccount("ABCDEF1", 11111);
    createAccount("ABCDE", 11111);
    createAccount("ABCDEF2", 123456);

    cout << getBalance("ABCDEF1") << " " << endl;
    addTransaction("ABCDEF1", 1000);
    cout << getBalance("ABCDEF1") << endl;
    cout << getBalance("ABCDE") << " " << endl;
    addTransaction("ABCDE", 1000);
    cout << getBalance("ABCDE") << endl;
    cout << getBalance("ABCDEF2") << " " << endl;
    addTransaction("ABCDEF2", 1000);
    cout << getBalance("ABCDEF2") << endl;
    cout << getBalance("ABCDEF3") << " " << endl;
    addTransaction("ABCDEF3", 1000);
    cout << getBalance("ABCDEF3") << endl;

    cout << deleteAccount("ABCDEF1") << endl;
    cout << deleteAccount("ABCDEF5") << endl;

    return 0;
}