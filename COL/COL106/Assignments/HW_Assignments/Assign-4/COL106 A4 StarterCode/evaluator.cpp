/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"

Evaluator::Evaluator()
{
    expr_trees;
    symtable = new SymbolTable();
}

bool isOperator(string c)
{
    return c == "ADD" || c == "SUB" || c == "MUL" || c == "DIV";
}

Evaluator::~Evaluator()
{
    delete[] expr_trees;
    delete symtable;
}

void Evaluator::parse(vector<string> code)
{
    vector<ExprTreeNode *> nodeStack;
    vector<string> operatorStack;

    for (string c : code[0]) // ............
    {
        if (c == '(')
        {
            operatorStack.push_back(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.back() != '(')
            {
                string op = operatorStack.back();
                operatorStack.pop_back();

                ExprTreeNode *rightNode = nodeStack.back();
                nodeStack.pop_back();
                ExprTreeNode *leftNode = nodeStack.back();
                nodeStack.pop_back();

                ExprTreeNode *newNode = new ExprTreeNode(); // ...............
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
                   ((c == "MUL" || c == "DIV") && (operatorStack.back() == "ADD" || operatorStack.back() == "SUB")))
            {
                string op = operatorStack.back();
                operatorStack.pop_back();

                ExprTreeNode *rightNode = nodeStack.back();
                nodeStack.pop_back();
                ExprTreeNode *leftNode = nodeStack.back();
                nodeStack.pop_back();

                ExprTreeNode *newNode = new ExprTreeNode(op, ); // .............
                newNode->left = leftNode;
                newNode->right = rightNode;
                nodeStack.push_back(newNode);
            }
            operatorStack.push_back(c);
        }
        else if (c == "VAL" || c == "VAR")
        {
            string operand = "VAL";
            int i = 0;
            while (isalnum(c))
            {
                operand += c;
                c = expression[++i];
            }
            nodeStack.push_back(new ExprTreeNode(operand, )) //................
        }
    }

    while (!operatorStack.empty())
    {
        string op = operatorStack.back();
        operatorStack.pop_back();

        ExprTreeNode *rightNode = nodeStack.back();
        nodeStack.pop_back();
        ExprTreeNode *leftNode = nodeStack.back();
        nodeStack.pop_back();

        ExprTreeNode *newNode = new ExprTreeNode(string(1, op)); // ..................
        newNode->left = leftNode;
        newNode->right = rightNode;
        nodeStack.push_back(newNode);
    }

    return nodeStack.back();
}

void Evaluator::eval()
{
}