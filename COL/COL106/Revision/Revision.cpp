#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// #define int long long
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define print_any(vec)     \
    for (auto value : vec) \
        cout << value << " ";
#define next_line cout << endl;

const int N = 1e5 + 2, MOD = 1e9 + 7;

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a TreeNode structure for the expression tree
struct TreeNode
{
    string value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const string &val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to check if a character is an operator
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to build the expression tree
TreeNode *buildExpressionTree(const string &expression)
{
    vector<TreeNode *> nodeStack;
    vector<char> operatorStack;

    for (char c : expression)
    {
        if (c == '(')
        {
            operatorStack.push_back(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.back() != '(')
            {
                char op = operatorStack.back();
                operatorStack.pop_back();

                TreeNode *rightNode = nodeStack.back();
                nodeStack.pop_back();
                TreeNode *leftNode = nodeStack.back();
                nodeStack.pop_back();

                TreeNode *newNode = new TreeNode(string(1, op));
                newNode->left = leftNode;
                newNode->right = rightNode;
                nodeStack.push_back(newNode);
            }

            if (!operatorStack.empty() && operatorStack.back() == '(')
            {
                operatorStack.pop_back();
            }
        }
        else if (isOperator(c))
        {
            while (!operatorStack.empty() && operatorStack.back() != '(' &&
                   ((c == '*' || c == '/') && (operatorStack.back() == '+' || operatorStack.back() == '-')))
            {
                char op = operatorStack.back();
                operatorStack.pop_back();

                TreeNode *rightNode = nodeStack.back();
                nodeStack.pop_back();
                TreeNode *leftNode = nodeStack.back();
                nodeStack.pop_back();

                TreeNode *newNode = new TreeNode(string(1, op));
                newNode->left = leftNode;
                newNode->right = rightNode;
                nodeStack.push_back(newNode);
            }
            operatorStack.push_back(c);
        }
        else if (isalnum(c))
        {
            string operand = "";
            int i = 0;
            while (isalnum(c))
            {
                operand += c;
                c = expression[++i];
            }
            nodeStack.push_back(new TreeNode(operand));
        }
    }

    while (!operatorStack.empty())
    {
        char op = operatorStack.back();
        operatorStack.pop_back();

        TreeNode *rightNode = nodeStack.back();
        nodeStack.pop_back();
        TreeNode *leftNode = nodeStack.back();
        nodeStack.pop_back();

        TreeNode *newNode = new TreeNode(string(1, op));
        newNode->left = leftNode;
        newNode->right = rightNode;
        nodeStack.push_back(newNode);
    }

    return nodeStack.back();
}

// Function to print the infix expression using parentheses
void printInfix(TreeNode *root)
{
    if (root)
    {
        if (root->left || root->right)
        {
            cout << "(";
        }
        printInfix(root->left);
        cout << root->value;
        printInfix(root->right);
        if (root->left || root->right)
        {
            cout << ")";
        }
    }
}

void printPostfix(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    printPostfix(root->left);
    printPostfix(root->right);
    cout << root->value << " ";
}

int main()
{
    string expression = "((((a/b))*c)+q)";
    TreeNode *root = buildExpressionTree(expression);

    cout << "Infix Expression: ";
    printPostfix(root);
    cout << endl;

    return 0;
}
