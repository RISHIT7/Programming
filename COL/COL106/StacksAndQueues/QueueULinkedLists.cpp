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

class Queue
{
    int front = -1;
    int back = -1;
    node* head;
public:
    Queue(node *&Head)
    {
        head = Head;
    }
    void push(int val)
    {
        node* new_node = new node(val);
        if (front == -1)
        {
            front++;
            head = new_node;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        back++;
    }
    int pop()
    {
        node *temp = head;
        if (front == back + 1)
        {
            cout << "No element to pop" << endl;
            return -1;
        }
        front++;
        for (int i = 0; i < front-1; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void peek()
    {
        node *temp = head;
        if (front == back + 1)
        {
            cout << "No element to peek" << endl;
            return;
        }
        for (int i = 0; i < front; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    bool isEmpty()
    {
        return front == back+1;
    }
};

int main()
{
    node *head = NULL;
    Queue Q = Queue(head);
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.peek();
    cout << Q.pop() << endl;
    Q.peek();
    cout << Q.pop() << endl;
    Q.peek();
    cout << Q.pop() << endl;
    cout << Q.isEmpty() << endl;
    return 0;
}