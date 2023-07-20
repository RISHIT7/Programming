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

bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();

    return false;
}

int LCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc - 1];
}

Node *LCA2(Node *root, int n2, int n1)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *leftLCA = LCA2(root->left, n2, n1);
    Node *rightLA = LCA2(root->right, n2, n1);

    if (leftLCA && rightLCA)
    {
        return root;
    }
    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA;
}

int main()
{
    return 0;
}