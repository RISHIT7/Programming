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

int search(vector<int> inorder, int start, int end, int curr)
{
    int idx = 0;
    while (inorder[idx] != curr)
    {
        idx += 1;
    }
    return idx+1;
}

Node *buildTree(vector<int> postorder, vector<int> inorder, int start, int end)
{
    static int postidx = end - 1;

    if (start > end)
    {
        return NULL;
    }

    int curr = postorder[postidx];
    postidx--;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->right = buildTree(postorder, inorder, pos + 1, end);
    node->left = buildTree(postorder, inorder, start, pos - 1);

    return node;
}

void inorder_print(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_print(root->left);
    cout << root->data <<  " ";
    inorder_print(root->right);
}

int main()
{
    vector<int> postorder = {4, 2, 5, 3, 1};
    vector<int> inorder = {4, 2, 1, 5, 3};
    Node *root = buildTree(postorder, inorder, 0, inorder.size());
    inorder_print(root);
    return 0;
}