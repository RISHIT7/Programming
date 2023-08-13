#include <iostream>
using namespace std;
#define C 2

/* PART B */
/* Dynamic Stacks */

class Stack_B
{
private:
    int *stk;         // The dynamic array
    int size;         // Number of elements in the stack
    int capacity = C; // Capacity of the stack

public:
    int t;
    // Constructor
    Stack_B()
    {
        stk = new int[capacity];
        t = -1;
    }

    // Destructor
    ~Stack_B()
    {
        // delete []stk;
    }

    void push(int data)
    {
        if (t >= capacity - 1) // Reallocate space and copy
        {
            int *temp = new int[capacity * C];
            for (int i = 0; i <= t; i++)
            {
                temp[i] = stk[i];
            }

            // delete[] stk;
            stk = temp;
            capacity *= C;
        }
        stk[++t] = data;
    }

    int pop()
    {
        int result = stk[t];
        if (t <= capacity / (C * C)) // Reallocate space and copy
        {
            int *temp = new int[capacity / (C * C)];
            for (int i = 0; i <= t; i++)
            {
                temp[i] = stk[i];
            }
            // delete[] stk;
            stk = temp;
            capacity /= (C * C);
        }
        t--;
        return result;
    }

    int get_element_from_top(int idx)
    {
        if (t < idx)
        {
            throw std::runtime_error("Index out of range");
        }
        return stk[t - idx];
    }

    int get_element_from_bottom(int idx)
    {
        if (idx > t)
        {
            throw std::runtime_error("Index out of range");
        }
        return stk[idx];
    }

    void print_stack(bool top_or_bottom)
    {
        if (top_or_bottom == true)
        {
            for (int i = t; i >= 0; i--)
            {
                cout << stk[i] << endl;
            }
        }
        else
        {
            for (int i = 0; i <= t; i++)
            {
                cout << stk[i] << endl;
            }
        }
    }

    int add()
    {
        if (t >= 1)
        {
            int tmp1 = stk[t];
            int tmp2 = stk[t - 1];
            t--;
            int fin = tmp1 + tmp2;
            stk[t] = fin;
            return fin;
        }
        else
        {
            throw std::runtime_error("Not Enough Arguments");
        }
    }

    int subtract()
    {
        if (t >= 1)
        {
            int tmp1 = stk[t];
            int tmp2 = stk[t - 1];
            t--;
            int fin = tmp2 - tmp1;
            stk[t] = fin;
            return fin;
        }
        else
        {
            throw std::runtime_error("Not Enough Arguments");
        }
    }

    int multiply()
    {
        if (t >= 1)
        {
            int tmp1 = stk[t];
            int tmp2 = stk[t - 1];
            t--;
            int fin = tmp1 * tmp2;
            stk[t] = fin;
            return fin;
        }
        else
        {
            throw std::runtime_error("Not Enough Arguments");
        }
    }

    int divide()
    {
        if (t >= 1)
        {
            int tmp1 = stk[t];
            if (tmp1 != 0)
            {
                int tmp2 = stk[t - 1];
                t--;
                int fin = tmp2 / tmp1;
                stk[t] = fin;
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

        return &stk[t]; // doubtful
    }

    int get_size() // Get the size of the stack
    {
        return t + 1;
    }

    void temp_check()
    {
        for (int i = 0; i <= t; i++)
        {
            cout << stk[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack_B st = Stack_B();
    st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout << st.get_size() << endl;
    cout << "---------- first iter ------------\n";
    st.temp_check();
    cout << "\n-------------------\n"
         << endl;
    cout << "The second element from bottom " << st.get_element_from_bottom(1) << endl; // for 1 2 3 4, we should get 2
    cout << "The sixth element from top  " << st.get_element_from_top(5) << endl;       // for 1 2 3 4, we should get 2
    cout << "The size of the stack " << st.get_size() << endl;
    int *s = st.get_stack();
    cout << "Getting the top int " << *s << endl;
    cout << "---------- second iter ------------\n";
    st.temp_check();
    cout << "\n-------------------\n"
         << endl;

    cout << "Top most element " << st.get_element_from_top(0) << endl;
    st.add();
    s = st.get_stack();
    cout << "Getting the top int " << *s << endl;
    cout << "---------- third iter ------------\n";
    st.temp_check();
    cout << "\n-------------------\n"
         << endl;

    cout << "Top most element after adding the top 2 elements " << st.get_element_from_top(0) << endl;
    st.divide();
    s = st.get_stack();
    cout << "Getting the top int " << *s << endl;
    cout << "---------- fourth iter ------------\n";
    st.temp_check();
    cout << "\n-------------------\n"
         << endl;

    cout << "Top most element after dividing the top 2 elements " << st.get_element_from_top(0) << endl;
    st.print_stack(false);
    st.pop();
    cout << st.get_size() << endl;
    return 0;
}