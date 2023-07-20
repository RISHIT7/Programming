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

int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int height = 0;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            height += 1;
        }
    }
    return height + 1;
}

bool balanced_height(Node *root)
{
    if (root->right == NULL and root->left == NULL)
    {
        return true;
    }
    else
    {
        int rheight = height(root->right);
        int lheight = height(root->left);
        if (abs(rheight - lheight) <= 1)
        {
            if (balanced_height(root->left) and balanced_height(root->right))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << balanced_height(root) << endl;

    return 0;
}