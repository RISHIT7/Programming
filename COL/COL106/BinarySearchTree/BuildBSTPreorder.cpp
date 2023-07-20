#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if(*preorderIdx >= n)
    {
        return NULL;
    }
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    return root;
}

int main()
{
    return 0;
}