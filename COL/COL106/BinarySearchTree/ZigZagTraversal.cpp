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

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << endl;

            if (leftToRight)
            {
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main()
{
    return 0;
}