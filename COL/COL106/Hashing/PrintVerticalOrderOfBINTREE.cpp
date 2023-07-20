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

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void getVerticalOrder(Node *root, int hdis, map<int, vi> &m)
{
    if (root == NULL)
    {
        return;
    }

    m[hdis].push_back(root->data); // O(logn)
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}
// total time complexity is O(nlogn)
signed main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vi> m;
    int hdis = 0;

    getVerticalOrder(root, hdis, m);

    map<int, vi>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->ss).size(); i++)
        {
            cout << (it->ss)[i] << " ";
        }
        next_line;
    }

    return 0;
}