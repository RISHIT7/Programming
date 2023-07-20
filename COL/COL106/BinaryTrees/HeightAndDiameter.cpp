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

// ------- O(n) ------- where n is the number of nodes
int calc_height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    int count = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            count += 1;
        }
    }
    return count + 1;
}

// ---------------- (O(n^2)) where n is the number of nodes
int calc_diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = calc_height(root->left);
    int rHeight = calc_height(root->right);
    int curr_diameter = lHeight + rHeight + 1;

    int lDiameter = calc_diameter(root->left);
    int rDiameter = calc_diameter(root->right);

    return max(curr_diameter, max(lDiameter, rDiameter));
}

int diameter(struct Node* root, int* height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = diameter(root->left, &lh);
    int rDiameter = diameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

int main()
{
    /*
                1
               / \
              2   3
             / \ / \
            4  56   7
              /  \
             8    9
            / \    \
          10   11   12
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->left->right = new Node(9);
    root->left->right->left->left = new Node(10);
    root->left->right->left->right = new Node(11);
    root->right->left->right->right = new Node(12);

    cout << calc_height(root) << endl;
    cout << calc_diameter(root) << endl;
    int height = 0;
    cout<< diameter(root, &height)<<endl;
    return 0;
}