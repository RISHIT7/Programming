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
		if (remove->next == NULL)
		{
			cout << "Element not present error" << endl;
			return;
		}
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

node *reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *Next;
    while (curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    head = prev;
    delete curr;

    return head;
}

node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }
    return prevptr;
}

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    // this can cause problem while in any list, hence we need to remove it
    temp->next = startNode;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// remove cycle

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
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

    node *rhead = reverse(head);
    insertAt(rhead, 1, 3);
    insertAtTail(rhead, 1);
    node *rrhead = reverse(rhead);

    display(rrhead);

    insertAtTail(rrhead, 5);
    insertAtTail(rrhead, 6);

    display(rrhead);

    node *krhead = reversek(rrhead, 2);

    display(krhead);

    makeCycle(krhead, 3);
    // display(krhead);
    cout << detectCycle(krhead) << endl;
    removeCycle(krhead);
    
    display(krhead);

    return 0;
}