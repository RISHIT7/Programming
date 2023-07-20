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

void swap(int *a, int *b) // since we were passing address, we take input as int pointers
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev) // since these are address to the node pointers, we take input as pointers to node pointer
{
    if (root == NULL)
    {
        return;
    }

    calcPointers(root->left, first, mid, last, prev); // these arguments are still pointers to node pointers

    if (*prev && root->data < (*prev)->data) // *prev is a Node pointer
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void restoreBST(Node *root)
{
    Node *first, *mid, *last, *temp; // declaring node pointers
    first = NULL; // assigning value NULL to node pointers, these are still pointers and not the node !
    mid = NULL;
    last = NULL;
    temp = NULL;

    calcPointers(root, &first, &mid, &last, &temp); // passing by reference, the address to the node pointers

    if (first && last)
    {
        swap(&(first->data), &(last->data)); // here we are passing by reference the address to the int values, we do want to be able to change the value of the int, hence send this way
    }
    else if (first & mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

int main()
{
    return 0;
}