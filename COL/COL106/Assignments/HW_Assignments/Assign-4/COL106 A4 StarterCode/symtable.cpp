/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
#include <iostream>
using namespace std;

SymEntry *insert_node(SymEntry *node, string k, UnlimitedRational *v)
{
    if (node == nullptr)
    {
        return new SymEntry(k, v);
    }

    if (k < node->key)
    {
        node->left = insert_node(node->left, k, v);
    }
    else if (k > node->key)
    {
        node->right = insert_node(node->right, k, v);
    }

    return node;
}

void SymbolTable::insert(string k, UnlimitedRational *v)
{
    if (root == nullptr)
    {
        root = new SymEntry(k, v);
    }
    else
    {
        root = insert_node(root, k, v);
    }
    size++;
}

SymEntry *minNode(SymEntry *node)
{
    SymEntry *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

SymEntry *remove_node(SymEntry *node, string k)
{
    if (node == nullptr)
    {
        return node;
    }

    if (k < node->key)
    {
        node->left = remove_node(node->left, k);
    }
    else if (k > node->key)
    {
        node->right = remove_node(node->right, k);
    }
    else
    {
        if (node->left == nullptr)
        {
            SymEntry *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            SymEntry *temp = node->left;
            delete node;
            return temp;
        }

        SymEntry *temp = minNode(node->right);

        node->key = temp->key;
        node->val = temp->val;

        node->right = remove_node(node->right, temp->key);
    }
    return node;
}

void SymbolTable::remove(string k)
{
    root = remove_node(root, k);
    size--;
}

SymEntry *search_node(SymEntry *node, string k)
{
    if (node == nullptr)
    {
        return nullptr; 
    }

    if (k == node->key)
    {
        return node;
    }
    else if (k < node->key)
    {
        return search_node(node->left, k);
    }
    else
    {
        return search_node(node->right, k);
    }
}

UnlimitedRational *SymbolTable::search(string k)
{
    SymEntry* node = search_node(root, k);
    if (node != nullptr)
    {
        return node->val;
    }
    else
    {
        UnlimitedInt* minus_one = new UnlimitedInt(-1);
        UnlimitedInt* one = new UnlimitedInt(1);
        UnlimitedRational* minus_1 = new UnlimitedRational(minus_one, one);
        return minus_1;
    }
}

int SymbolTable::get_size()
{
    return size;
}

SymEntry *SymbolTable::get_root()
{
    return root;
}