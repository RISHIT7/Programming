#include <iostream>
#include <stack_a.h>
#include <stdexcept>
using namespace std;

/* PART A */
/* Stacks using Fixed Size Arrays */

class Stack_A
{
private:
    int stk[1024]; // The fixed size array
    int size;      // Number of elements in the stack

public:
    int top;
    // Constructor
    Stack_A()
    {
        stk[1024];
        top = -1;
    }

    void push(int data)
    {
        // top is the int storing the index of the top element
        // size is the varibale storing size of the array
        // stk is an array of length 1024 storing the values
        if (top == -1)
        {
            top = 0;
            stk[top] = data;
        }
        else if (top < 1023)
        {
            top++;
            stk[top] = data;
        }
        else if (top >= 1023)
        {
            throw std::runtime_error("Stack Full");
        }
    }

    int pop()
    {
        // returns and pops the top value
        // hence size reduces by 1 and top decreases by one
        // base cases
        if (top == 0)
        {
            int temp = stk[top];
            top = -1;
            return temp;
        }
        else if (top == -1)
        {
            throw std::runtime_error("Empty Stack");
        }
        else
        {
            int temp = stk[top];
            top--;
            return temp;
        }
        return -1;
    }

    int get_element_from_top(int idx)
    {
        if (top < idx)
        {
            throw std::runtime_error("Index out of range");
        }
        return stk[top - idx];
    }

    int get_element_from_bottom(int idx)
    {
        if (idx > top)
        {
            throw std::runtime_error("Index out of range");
        }
        return stk[idx];
    }

    void print_stack(bool top_or_bottom)
    {
        if (top_or_bottom == true)
        {
            for (int i = top; i >= 0; i--)
            {
                cout << stk[i] << endl;
            }
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << stk[i] << endl;
            }
        }
    }

    int add()
    {
        if (top >= 1)
        {
            int tmp1 = stk[top];
            int tmp2 = stk[top - 1];
            top--;
            int fin = tmp1 + tmp2;
            stk[top] = fin;
            return fin;
        }
        else
        {
            throw std::runtime_error("Not Enough Arguments");
        }
    }

    int subtract()
    {
        if (top >= 1)
        {
            int tmp1 = stk[top];
            int tmp2 = stk[top - 1];
            top--;
            int fin = tmp2 - tmp1;
            stk[top] = fin;
            return fin;
        }
        else
        {
            throw std::runtime_error("Not Enough Arguments");
        }
    }

    int multiply()
    {
        if (top >= 1)
        {
            int tmp1 = stk[top];
            int tmp2 = stk[top - 1];
            top--;
            int fin = tmp1 * tmp2;
            stk[top] = fin;
            return fin;
        }
        else
        {
            throw std::runtime_error("Not Enough Arguments");
        }
    }

    int divide()
    {
        if (top >= 1)
        {
            int tmp1 = stk[top];
            if (tmp1 != 0)
            {
                int tmp2 = stk[top - 1];
                top--;
                int fin = tmp2 / tmp1;
                stk[top] = fin;
                return fin;
            }
            else
            {
                throw std::runtime_error("Divide by Zero Error");
            }
        }
        else
        {
            throw std::runtime_error("Not Enough Arguments");
        }
    }

    int *get_stack() // Get a pointer to the array
    {

        return &stk[top]; // doubtful
    }

    int get_size() // Get the size of the stack
    {
        return top + 1;
    }

    void temp_check()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stk[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack_A st = Stack_A();
    // // st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    // cout << st.get_size() << endl;
    // cout << "---------- first iter ------------\n";
    // st.temp_check();
    // cout << "\n-------------------\n"
    //      << endl;
    // cout << "The second element from bottom " << st.get_element_from_bottom(1) << endl; // for 1 2 3 4, we should get 2
    // cout << "The sixth element from top  " << st.get_element_from_top(5) << endl;       // for 1 2 3 4, we should get 2
    // cout << "The size of the stack " << st.get_size() << endl;
    // int *s = st.get_stack();
    // cout << "Getting the top int " << *s << endl;
    // cout << "---------- second iter ------------\n";
    // st.temp_check();
    // cout << "\n-------------------\n"
    //      << endl;

    // cout << "Top most element " << st.get_element_from_top(0) << endl;
    // st.add();
    // s = st.get_stack();
    // cout << "Getting the top int " << *s << endl;
    cout << "---------- third iter ------------\n";
    st.temp_check();
    cout << "\n-------------------\n"
         << endl;

    // cout << "Top most element after adding the top 2 elements " << st.get_element_from_top(0) << endl;
    st.divide();
    // s = st.get_stack();
    // cout << "Getting the top int " << *s << endl;
    cout << "---------- fourth iter ------------\n";
    st.temp_check();
    cout << "\n-------------------\n"
         << endl;

    cout << "Top most element after dividing the top 2 elements " << st.get_element_from_top(0) << endl;
    // st.print_stack(false);
    // st.pop();
    // cout << st.get_size() << endl;
    return 0;
}