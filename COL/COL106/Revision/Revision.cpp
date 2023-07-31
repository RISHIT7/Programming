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

const int N = 1e5 + 2, MOD = 1e9 + 7;

struct node
{
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
    }

    node *temp = new node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(node *&head, int val)
{
    node *new_node = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

void deleteAtHead(node *&head)
{
    node *remove = head;
    head = head->next;
    head->prev = NULL;

    delete remove;
}

void deletion(node *&head, int val)
{
    if (head == val)
    {
        deleteAtHead(head);
    }

    node *temp = head;
    while (temp->data != val)
    {
        if (temp->next == NULL)
        {
            cout << "No element of this index" << endl;
            return;
        }
        temp = temp->next;
    }
    node *to_delete = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete to_delete;
}

signed main
{

    return 0;
}