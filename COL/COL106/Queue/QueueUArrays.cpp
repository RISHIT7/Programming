#include <bits/stdc++.h>
using namespace std;

#define n 100

class Queue
{
private:
    int front, back;
    int *arr;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int val)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (back + 1 < n)
        {
            back++;
            arr[back] = val;
            if (front == -1)
            {
                front++;
            }
        }
    }

    int pop()
    {
        if (front == back+1)
        {
            cout << "No element to pop" << endl;
            return -1;
        }
        front++;
        return arr[front - 1];
    }

    void peek()
    {
        if (front == back+1)
        {
            cout << "No element to peek" << endl;
            return;
        }
        cout << arr[front] << endl;
    }

    bool isEmpty()
    {
        return front == back+1;
    }
};

int main()
{
    Queue Q = Queue();
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