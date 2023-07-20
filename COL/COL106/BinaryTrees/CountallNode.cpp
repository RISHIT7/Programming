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

int count_all_nodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    int count = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            count += 1;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return count;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->left->right = new Node(9);
    root->left->right->left->left = new Node(10);
    root->left->right->left->right = new Node(11);
    root->right->left->right->right = new Node(12);

    cout << count_all_nodes(root) << endl;
    return 0;
}