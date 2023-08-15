#include <iostream> 
#include "stack_b.h"
#include <stdexcept>
using namespace std;
#define C 2

Stack_B::Stack_B()
{
    capacity = C;
    stk = new int[capacity];
    size = 0;
}

Stack_B::~Stack_B()
{

    delete[] stk;
}

void Stack_B::push(int data)
{
    if (size - 1 >= capacity - 1) // Reallocate space and copy
    {
        int *temp = new int[capacity * C];
        for (int i = 0; i <= size - 1; i++)
        {
            temp[i] = stk[i];
        }

        // delete[] stk;
        stk = temp;
        capacity *= C;
    }
    stk[++size - 1] = data;
}

int Stack_B::pop()
{
    if (size - 1 == -1)
    {
        throw std::runtime_error("Empty Stack");
    }

    int result = stk[size - 1];
    if (size - 1 <= capacity / (C * C)) // Reallocate space and copy
    {
        int *temp = new int[capacity / (C * C)];
        for (int i = 0; i <= size - 1; i++)
        {
            temp[i] = stk[i];
        }
        // delete[] stk;
        stk = temp;
        capacity /= (C * C);
    }
    size--;
    return result;
}

int Stack_B::get_element_from_top(int idx)
{
    if (size - 1 < idx)
    {
        throw std::runtime_error("Index out of range");
    }
    return stk[size - 1 - idx];
}

int Stack_B::get_element_from_bottom(int idx)
{
    if (idx > size - 1)
    {
        throw std::runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_B::print_stack(bool top_or_bottom)
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

int Stack_B::add()
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

int Stack_B::subtract()
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

int Stack_B::multiply()
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

int Stack_B::divide()
{
    if (size - 1 >= 1)
    {
        int tmp1 = stk[size - 1];
        if (tmp1 != 0)
        {
            int tmp2 = stk[size - 1 - 1];
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

int *Stack_B::get_stack() // Get a pointer to the array
{

    return stk; // doubtful
}

int Stack_B::get_size() // Get the size of the stack
{
    return size;
}

/* PART B */
/* Dynamic Stacks */

// class Stack_B
// {
// private:
//     int *stk;     // The dynamic array
//     int size;     // Number of elements in the stack
//     int capacity; // Capacity of the stack

// public:
//     int t;
//     // Constructor
//     Stack_B()
//     {
//         capacity = C;
//         stk = new int[capacity];
//         t = -1;
//     }

//     // Destructor
//     ~Stack_B()
//     {
//         // delete []stk;
//     }

//     void push(int data)
//     {
//         if (t >= capacity - 1) // Reallocate space and copy
//         {
//             int *temp = new int[capacity * C];
//             for (int i = 0; i <= t; i++)
//             {
//                 temp[i] = stk[i];
//             }

//             // delete[] stk;
//             stk = temp;
//             capacity *= C;
//         }
//         stk[++t] = data;
//     }

//     int pop()
//     {
//         if (t == -1)
//         {
//             throw std::runtime_error("Empty stack");
//         }

//         int result = stk[t];
//         if (t <= capacity / (C * C)) // Reallocate space and copy
//         {
//             int *temp = new int[capacity / (C * C)];
//             for (int i = 0; i <= t; i++)
//             {
//                 temp[i] = stk[i];
//             }
//             // delete[] stk;
//             stk = temp;
//             capacity /= (C * C);
//         }
//         t--;
//         return result;
//     }

//     int get_element_from_top(int idx)
//     {
//         if (t < idx)
//         {
//             throw std::runtime_error("Index out of range");
//         }
//         return stk[t - idx];
//     }

//     int get_element_from_bottom(int idx)
//     {
//         if (idx > t)
//         {
//             throw std::runtime_error("Index out of range");
//         }
//         return stk[idx];
//     }

//     void print_stack(bool top_or_bottom)
//     {
//         if (top_or_bottom == true)
//         {
//             for (int i = t; i >= 0; i--)
//             {
//                 cout << stk[i] << endl;
//             }
//         }
//         else
//         {
//             for (int i = 0; i <= t; i++)
//             {
//                 cout << stk[i] << endl;
//             }
//         }
//     }

//     int add()
//     {
//         if (t >= 1)
//         {
//             int tmp1 = stk[t];
//             int tmp2 = stk[t - 1];
//             t--;
//             int fin = tmp1 + tmp2;
//             stk[t] = fin;
//             return fin;
//         }
//         else
//         {
//             throw std::runtime_error("Not Enough Arguments");
//         }
//     }

//     int subtract()
//     {
//         if (t >= 1)
//         {
//             int tmp1 = stk[t];
//             int tmp2 = stk[t - 1];
//             t--;
//             int fin = tmp2 - tmp1;
//             stk[t] = fin;
//             return fin;
//         }
//         else
//         {
//             throw std::runtime_error("Not Enough Arguments");
//         }
//     }

//     int multiply()
//     {
//         if (t >= 1)
//         {
//             int tmp1 = stk[t];
//             int tmp2 = stk[t - 1];
//             t--;
//             int fin = tmp1 * tmp2;
//             stk[t] = fin;
//             return fin;
//         }
//         else
//         {
//             throw std::runtime_error("Not Enough Arguments");
//         }
//     }

//     int divide()
//     {
//         if (t >= 1)
//         {
//             int tmp1 = stk[t];
//             if (tmp1 != 0)
//             {
//                 int tmp2 = stk[t - 1];
//                 t--;
//                 int fin = tmp2 / tmp1;
//                 stk[t] = fin;
//                 return fin;
//             }
//             else
//             {
//                 throw std::runtime_error("Divide by Zero Error");
//             }
//         }
//         else
//         {
//             throw std::runtime_error("Not Enough Arguments");
//         }
//     }

//     int *get_stack() // Get a pointer to the array
//     {

//         return &stk[t]; // doubtful
//     }

//     int get_size() // Get the size of the stack
//     {
//         return t + 1;
//     }

//     void temp_check()
//     {
//         for (int i = 0; i <= t; i++)
//         {
//             cout << stk[i] << " ";
//         }
//         cout << endl;
//     }
// };

