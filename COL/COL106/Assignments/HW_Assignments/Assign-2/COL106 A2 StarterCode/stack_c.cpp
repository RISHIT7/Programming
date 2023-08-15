#include <iostream>
#include "stack_c.h"
#include <stdexcept>
using namespace std;

int floor_c(float a)
{
    if ((int)(a*10)%10 == 0)
    {
        return (int)a;
    }
    else
    {
        return (int)a-1;
    }
}

Stack_C::Stack_C()
{
    stk = new List();
    stk = stk;
}

Stack_C::~Stack_C() // might be wrong
{
    delete stk;
}

void Stack_C::push(int data)
{
    stk->insert(data);
}

int Stack_C::pop()
{
    int data = stk->delete_tail();
    return data;
}

int Stack_C::get_element_from_top(int idx) // test these, might be wrong
{
    if (stk->get_size() - 1 < idx)
    {
        throw std::runtime_error("Index out of range");
    }
    Node *trav = stk->get_head();
    while (idx != stk->get_size())
    {
        trav = trav->next;
        idx++;
    }
    return trav->get_value();
}

int Stack_C::get_element_from_bottom(int idx) // test these, might be wrong
{
    if (idx > stk->get_size() - 1)
    {
        throw std::runtime_error("Index out of range");
    }
    Node *trav = stk->get_head()->next;
    while (idx != 0)
    {
        trav = trav->next;
        idx--;
    }
    return trav->get_value();
}

// returns sentinel_tail
Node *get_tail(Node *sentinel_head)
{
    Node *sentinel_tail = sentinel_head;
    while (sentinel_tail->next != nullptr)
    {
        sentinel_tail = sentinel_tail->next;
    }
    return sentinel_tail;
}

void Stack_C::print_stack(bool top_or_bottom)
{

    if (top_or_bottom == true)
    {
        Node *trav = get_tail(stk->get_head())->prev;
        for (int i = stk->get_size() - 1; i >= 0; i--)
        {
            cout << trav->get_value() << endl;
            trav = trav->prev;
        }
    }
    else
    {
        Node *trav = stk->get_head()->next;
        for (int i = 0; i < stk->get_size(); i++)
        {
            cout << trav->get_value() << endl;
            trav = trav->next;
        }
    }
}

int Stack_C::add()
{
    if (stk->get_size() - 1 >= 1)
    {
        Node *trav = get_tail(stk->get_head());
        int tmp1 = trav->prev->get_value();
        int tmp2 = trav->prev->prev->get_value();
        int fin = tmp1 + tmp2;
        stk->delete_tail();
        stk->delete_tail();
        stk->insert(fin);
        return fin;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_C::subtract()
{
    if (stk->get_size() - 1 >= 1)
    {
        Node *trav = get_tail(stk->get_head());
        int tmp1 = trav->prev->get_value();
        int tmp2 = trav->prev->prev->get_value();
        int fin = tmp2 - tmp1;
        stk->delete_tail();
        stk->delete_tail();
        stk->insert(fin);
        return fin;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_C::multiply()
{
    if (stk->get_size() - 1 >= 1)
    {
        Node *trav = get_tail(stk->get_head());
        int tmp1 = trav->prev->get_value();
        int tmp2 = trav->prev->prev->get_value();
        int fin = tmp2 * tmp1;
        stk->delete_tail();
        stk->delete_tail();
        stk->insert(fin);
        return fin;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_C::divide()
{
    if (stk->get_size() - 1 >= 1)
    {
        Node *trav = get_tail(stk->get_head());
        int tmp1 = trav->prev->get_value();
        int tmp2 = trav->prev->prev->get_value();
        if (tmp1 != 0)
        {
            int fin = floor_c((float)tmp2 / tmp1);
            stk->delete_tail();
            stk->delete_tail();
            stk->insert(fin);
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

List *Stack_C::get_stack() // doubtful
{
    return stk;
}

int Stack_C::get_size()
{
    return stk->get_size();
}

