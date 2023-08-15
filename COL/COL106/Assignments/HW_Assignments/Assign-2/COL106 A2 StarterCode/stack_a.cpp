#include <iostream>
#include "stack_a.h"
#include <stdexcept>
using namespace std;

/* PART A */
/* Stacks using Fixed Size Arrays */

Stack_A::Stack_A()
{
    stk[1024];
    size = 0;
}

void Stack_A::push(int data)
{
    if (size == 0)
    {
        size = 1;
        stk[size - 1] = data;
    }
    else if (size < 1024)
    {
        size++;
        stk[size - 1] = data;
    }
    else if (size >= 1024)
    {
        throw std::runtime_error("Stack Full");
    }
}

int Stack_A::pop()
{
    if (size == 1)
    {
        int temp = stk[size - 1];
        size = 0;
        return temp;
    }

    else if (size == 0)
    {
        throw std::runtime_error("Empty Stack");
    }

    else
    {
        int temp = stk[size - 1];
        size--;
        return temp;
    }

    return -1;
}

int Stack_A::get_element_from_top(int idx)
{
    if (size - 1 < idx)
    {
        throw std::runtime_error("Index out of range");
    }
    return stk[size - 1 - idx];
}

int Stack_A::get_element_from_bottom(int idx)
{
    if (idx > size - 1)
    {
        throw std::runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_A::print_stack(bool top_or_bottom)
{
    if (top_or_bottom == true)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << stk[i] << endl;
        }
    }
    else
    {
        for (int i = 0; i <= size - 1; i++)
        {
            cout << stk[i] << endl;
        }
    }
}

int Stack_A::add()
{
    if (size - 1 >= 1)
    {
        int tmp1 = stk[size - 1];
        int tmp2 = stk[size - 1 - 1];
        size--;
        int fin = tmp1 + tmp2;
        stk[size - 1] = fin;
        return fin;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_A::subtract()
{
    if (size - 1 >= 1)
    {
        int tmp1 = stk[size - 1];
        int tmp2 = stk[size - 1 - 1];
        size--;
        int fin = tmp2 - tmp1;
        stk[size - 1] = fin;
        return fin;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_A::multiply()
{
    if (size - 1 >= 1)
    {
        int tmp1 = stk[size - 1];
        int tmp2 = stk[size - 1 - 1];
        size--;
        int fin = tmp1 * tmp2;
        stk[size - 1] = fin;
        return fin;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_A::divide()
{
    if (size - 1 >= 1)
    {
        int tmp1 = stk[size - 1];
        if (tmp1 != 0)
        {
            int tmp2 = stk[size - 1 - 1];
            cout<<tmp1<<" "<<tmp2<<endl;
            size--;
            int fin = tmp2 / tmp1;
            stk[size - 1] = fin;
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

int *Stack_A::get_stack() // Get a pointer to the array
{

    return stk; // doubtful
}

int Stack_A::get_size() // Get the size of the stack
{
    return size;
}

// int main()
// {
//     Stack_A st = Stack_A();
//     // // st.pop();
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);
//     st.push(6);
//     // cout << st.get_size() << endl;
//     // cout << "---------- first iter ------------\n";
//     // st.temp_check();
//     // cout << "\n-------------------\n"
//     //      << endl;
//     // cout << "The second element from bottom " << st.get_element_from_bottom(1) << endl; // for 1 2 3 4, we should get 2
//     // cout << "The sixth element from top  " << st.get_element_from_top(5) << endl;       // for 1 2 3 4, we should get 2
//     // cout << "The size of the stack " << st.get_size() << endl;
//     // int *s = st.get_stack();
//     // cout << "Getting the top int " << *s << endl;
//     // cout << "---------- second iter ------------\n";
//     // st.temp_check();
//     // cout << "\n-------------------\n"
//     //      << endl;

//     // cout << "Top most element " << st.get_element_from_top(0) << endl;
//     // st.add();
//     // s = st.get_stack();
//     // cout << "Getting the top int " << *s << endl;
//     cout << "---------- third iter ------------\n";
//     st.print_stack(true);
//     cout << "\n-------------------\n"
//          << endl;

//     // cout << "Top most element after adding the top 2 elements " << st.get_element_from_top(0) << endl;
//     st.divide();
//     // s = st.get_stack();
//     // cout << "Getting the top int " << *s << endl;
//     cout << "---------- fourth iter ------------\n";
//     st.print_stack(true);
//     cout << "\n-------------------\n"
//          << endl;

//     cout << "Top most element after dividing the top 2 elements " << st.get_element_from_top(0) << endl;
//     // st.print_stack(false);
//     // st.pop();
//     // cout << st.get_size() << endl;
//     return 0;
// }