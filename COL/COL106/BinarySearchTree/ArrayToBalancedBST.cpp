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
        right = NULL;
        left = NULL;
    }
};

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;

    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr[], start, mid - 1);
    root->right = sortedArrayToBST(arr[], mid + 1, end);

    return root;
}

int main()
{

    return 0;
}