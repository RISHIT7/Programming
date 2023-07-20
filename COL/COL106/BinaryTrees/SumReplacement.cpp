#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void sumReplace(Node *root)
{
    if (root != NULL)
    {
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->left->right;
    }
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void bfs(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
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
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->left->right->left = new Node(8);
    // root->right->left->right = new Node(9);
    // root->left->right->left->left = new Node(10);
    // root->left->right->left->right = new Node(11);
    // root->right->left->right->right = new Node(12);

    bfs(root);
    cout << endl;
    Node *n_root = replace_with_sum(root);

    bfs(root);

    return 0;
}