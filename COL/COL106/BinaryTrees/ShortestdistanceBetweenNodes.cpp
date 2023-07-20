#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data n1 || root->data == n1)
    {
        return root;
    }
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL and right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    if (right != NULL)
    {
        return LCA(root->right, n1, n2);
    }
}

int find_dist(Node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }
    int left = find_dist(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return find_dist(root->right, k, dist + 1);
}

int dist_between_nodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = find_dist(lca, n1, 0);
    int d2 = find_dist(lca, n2, 0);
    return d1 + d2;
}

int main()
{
    return 0;
}