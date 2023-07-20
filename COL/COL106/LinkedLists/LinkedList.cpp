#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAt(node *&head, int index, int val)
{
    node *n = new node(val);
    node *temp = head;
    while (index > 1)
    {
        if (temp->next == NULL)
        {
            cout << "Index out of range" << endl;
            return;
        }
        temp = temp->next;
        index--;
    }
    n->next = temp->next;
    temp->next = n;
}

void deletionAtHead(node *&head)
{
    node *remove = head;
    head = head->next;
    delete remove;
}

void deletion(node *&head, int val)
{
    node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    if (temp->data == val)
    {
        deletionAtHead(head);
        return;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *remove = temp->next;
    temp->next = temp->next->next;

    delete remove;
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool isPresent(node *head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int search(node *head, int val)
{
    int index = 0;
    node *temp = head;
    while (temp->data != val)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        index++;
        temp = temp->next;
    }
    return index;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtTail(head, 4);
    insertAt(head, 2, 3);
    deletion(head, 3);
    deletionAtHead(head);
    cout << search(head, 4) << endl;
    cout << search(head, 5) << endl;

    display(head);
    return 0;
}