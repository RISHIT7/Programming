#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    struct Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

// case 1
void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

// case 2
int printNodesAtk(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }
    int dl = printNodesAtk(root->left, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printNodesAtk(root->right, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    return 0;
}