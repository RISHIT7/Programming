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

struct node
{
    int data;
    node* right;
    node* left;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

node* insertBST(node* root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return root;
    }
    if (root->data < val){
        return insertBST(root->left, val);
    }
    else {
        return insertBST(root->right, val);
    }    
    return root;
}

int main() {
    node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    return 0;
}