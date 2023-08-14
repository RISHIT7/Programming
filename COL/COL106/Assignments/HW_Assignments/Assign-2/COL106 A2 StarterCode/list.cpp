#include <iostream>
#include "node.cpp"
#include "list.h"
using namespace std;

/* PART B */
/* Stacks using Linked Lists */

/*
Linked Lists with Sentinels
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/

List::List()
{
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
    sentinel_head->prev = nullptr;
    List::sentinel_tail->next = nullptr;
    size = 0;
}

List::~List()
{
    Node *current = sentinel_head;
    Node *next;
    while (current != nullptr)
    {
        next = current->next;
        free(current);
        current = next;
    }
    sentinel_head = nullptr;
    sentinel_tail = nullptr;
}

// Insert an element at the tail of the linked list
void List::insert(int v)
{
    Node *trav = sentinel_tail->prev;
    Node *new_node = new Node(v, sentinel_tail, trav);
    trav->next = new_node;
    sentinel_tail->prev = new_node;
    size++;
}

// Delete the tail of the linked list and return the value
// You need to delete the valid tail element, not the sentinel
int List::delete_tail()
{
    if (size == 0)
    {
        throw std::runtime_error("Empty Stack");
    }
    else
    {
        Node *tail = sentinel_tail->prev;
        cout << "check: " << tail->get_value() << endl;
        int temp = tail->get_value();
        Node *new_tail = tail->prev;
        cout << "check: " << new_tail->is_sentinel_node() << endl;
        new_tail->next = sentinel_tail;
        sentinel_tail->prev = new_tail;
        size--;

        delete tail;
        return temp;
    }
}

// Return the size of the linked list
// Do not count the sentinel elements
int List::get_size()
{
    return size;
}

// Return a pointer to the sentinel head of the linked list
Node *List::get_head()
{
    return sentinel_head;
}

// print linked list
void print(Node *sentinel_head)
{
    Node *trav = sentinel_head->next;
    cout << "sentinel_head"
         << "<->";
    while (trav->next != nullptr)
    {
        cout << trav->get_value() << "<->";
        trav = trav->next;
    }
    cout << "sentinel_tail" << endl;
}

int main()
{
    List L = List();
    L.insert(5);
    cout << L.get_size() << endl;
    cout << "printing List..." << endl;
    print(L.get_head());
    // cout << L.get_head()->next->get_value() << endl;
    L.insert(6);
    cout << L.get_size() << endl;
    cout << "printing List..." << endl;
    print(L.get_head());
    // cout << L.get_head()->next->next->get_value() << endl;
    L.delete_tail();
    cout << L.get_size() << endl;
    cout << "printing List..." << endl;
    print(L.get_head());
    // cout << L.get_head()->next->get_value() << endl;
    L.delete_tail();
    cout << L.get_size() << endl;
    cout << "printing List..." << endl;
    print(L.get_head());
    L.delete_tail();
    cout << L.get_size() << endl;
    cout << "printing List..." << endl;
    print(L.get_head());
    return 0;
}