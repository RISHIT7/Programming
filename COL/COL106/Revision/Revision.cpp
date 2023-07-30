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

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
    }

    temp->next = head;
    head = temp;
}

void insertAtTail(node *&head, int val)
{
    node *new_node = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = new_node;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAt(node *&head, int index, int val)
{
    node *new_node = new node(val);
    node *trav = head;
    while (index > 1)
    {
        if (trav->next == NULL)
        {
            cout << "Index out of range" << endl;
            return;
        }
        trav = trav->next;
        index--;
    }
    new_node->next = trav->next;
    trav->next = new_node;
}

void deletionAtHead(node *&head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    node *remove = head;
    head = head->next;
    delete remove;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }

    if (head->data == val)
    {
        deletionAtHead(head);
        return;
    }

    node *trav = head;
    while (trav->next->data != val)
    {
        if (trav->next == NULL)
        {
            cout << "Element not found" << endl;
            return;
        }
        trav = trav->next;
    }
    node *remove = trav->next;
    trav->next = trav->next->next;
    delete remove;
}

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

signed main()
{
    node *head = new node(2);
    insertAtHead(head, 1);
    display(head);
    return 0;
}