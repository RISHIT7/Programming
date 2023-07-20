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

int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = maxPathSum(root->left, ans);
    int right = maxPathSum(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right),
                      max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main()
{
    return 0;
}
