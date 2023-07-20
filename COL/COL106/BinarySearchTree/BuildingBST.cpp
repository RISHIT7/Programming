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

Node *insertBST(int val, Node *root)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(val, root->left);
    }
    else
    {
        root->right = insertBST(val, root->right);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* buildBST(vector<int> arr, Node* root)
{
    root = insertBST(arr[0], root);
    for (int i = 1; i < arr.size(); i++)
    {
        insertBST(arr[i], root);
    }
    return root;
}

int main()
{
    vector<int> input = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(input, NULL);
    inorder(root);
    cout << endl;
    return 0;
}