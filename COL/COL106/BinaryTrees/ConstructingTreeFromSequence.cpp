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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i < end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos-1);
    node->right = buildTree(preeorder, inorder, pos+1, end)

    return node;
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    return 0;
}