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

struct node
{
    node *next;
    int data;

    node(int val)
    {
        next = NULL;
        data = val;
    }
};

bool has_cycle(node* head)
{
    node* fast = head;
    node* slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast =  fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

node* detect_cyclic_node(node* head)
{
    node* fast = head;
    node* slow = head;

    bool is_cyclic = has_cycle(head);
    if (not is_cyclic)
    {
        return NULL;
    }
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            break;
        }
    }

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

signed main()
{
}