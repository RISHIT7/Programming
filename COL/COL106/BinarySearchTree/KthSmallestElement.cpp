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

void inorder_vec(Node *root, vector<int> *inorder)
{
    if (root == NULL)
    {
        return;
    }
    inorder_vec(root->left, inorder);
    inorder->push_back(root->data);
    inorder_vec(root->right, inorder);
}

int kthSmallest(Node *root, int k)
{
    vector<int> inorder = {};
    inorder_vec(root, &inorder);
    return inorder[k-1];
}

int main()
{
    Node *root = new Node(5);
    root->right = new Node(6);
    root->left = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    cout<<kthSmallest(root, 3)<<endl;;
    return 0;
}