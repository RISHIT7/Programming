#pragma once
#include "ulimitedrational.h"
#include "symtable.h"
#include <string>

class ExprTreeNode {
public:
    string type; // Can be "ADD", "SUB", "MUL", "DIV", "MOD" or "VAL"

    // Stores a value in case type is "VAL" 
    UnlimitedRational* val; 
    
    // To store the value of the expression rooted at the subtree at the node
    UnlimitedRational* evaluated_value; 

    ExprTreeNode* left;
    ExprTreeNode* right;

    ExprTreeNode();

    ExprTreeNode(string t, UnlimitedInt* v);

    ~ExprTreeNode();
};