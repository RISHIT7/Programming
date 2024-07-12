#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int noGoodNodes(Node* root, int max)
{
    if (root == nullptr)
        return 0;
    
    if (root->val >= max)
    {
        max = root->val;
    }
    int add;
    if (root->val >= max)
    {
        add = 1;
    }
    else
    {
        add = 0;
    }
    int res = add + noGoodNodes(root->left, max) + noGoodNodes(root->right, max);
    return res;
}

// {{min, max}, isBST}
pair<pair<int, int>, bool> validSubtree(Node* root, int Max, int Min)
{
    if (root == nullptr)
    {
        return {{Max, Min}, true};
    }

    if (root->val < Min || root->val > Max)
    {
        return {{Max, Min}, false};
    }

    pair<pair<int, int>, bool> left = validSubtree(root->left, root->val, Min); 
    pair<pair<int, int>, bool> right = validSubtree(root->right, Max, root->val); 

    if (!left.second || !right.second)
    {
        return {{Max, Min}, false};
    }
    if (left.first.second >= root->val || right.first.first <= root->val)
    {
        return {{Max, Min}, false};
    }
    int min_ = min(root->val, min(left.first.first, right.first.first));
    int max_ = max(root->val, max(left.first.second, right.first.second));
    
    return {{min_, max_}, true};
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* root = new Node(3);
    root->left = new Node(1);    
    root->right = new Node(4);    
    root->left->left = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(5);

    // Node* root = new Node(3);
    // root->left = new Node(1);
    // root->right = new Node(5);


    // int ans = noGoodNodes(root, -1);
    pair<pair<int, int>, bool> ans = validSubtree(root, INT_MAX, INT_MIN);
    cout << ans.second << endl;

    return 0;
}