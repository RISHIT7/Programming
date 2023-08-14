#include <iostream>
#include "node.h"
using namespace std;

Node::Node(bool sentinel)
{
    next = nullptr;
    prev = nullptr;
    is_sentinel = sentinel;
}

Node::Node(int v, Node* nxt, Node* prv)
{
    is_sentinel = false;
    value = v;
    next = nxt;
    prev = prv;
}

bool Node::is_sentinel_node()
{
    if (is_sentinel == true)
        return true;
    return false;
}

int Node::get_value()
{
    return value;
}

// int main()
// {
//     Node *head = new Node(3);
//     cout<<head->get_value()<<endl;
//     return 0;
// }