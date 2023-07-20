#include <iostream>
using namespace std;

#define n 100

class stack
{
private:
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow error" << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return -1;
        }
        top--;
        return arr[top + 1];
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "No element to peek" << endl;
            return;
        }
        cout << arr[top] << endl;
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

void insertAtBottom(stack &st, int ele)
{
    if (st.isEmpty())
    {
        st.push(ele);
        return;
    }
    int topele = st.pop();
    insertAtBottom(st, ele);

    st.push(topele);
}

void reverse(stack &st)
{
    if (st.isEmpty())
    {
        return;
    }
    int ele = st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.peek();
    cout << st.pop() << endl;
    st.peek();
    reverse(st);
    while(!st.isEmpty())
    {
        cout<<st.pop()<<" ";
    }cout<<endl;
    return 0;
}