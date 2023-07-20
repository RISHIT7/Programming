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
    }
};

bool isIdentical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else
    {
        bool cond1 = (root1->data == root2->data);
        bool cond2 = (isIdentical(root1->left, root2->left));
        bool cond3 = (isIdentical(root1->right, root2->right));
        return (cond1&&cond2&&cond3);
    }
}

int main()
{
    return 0;
}