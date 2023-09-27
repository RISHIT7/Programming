/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
// to be handled, cases with 0 sign values, when the output is 0
#include "ulimitedint.h"
#include <iostream>
using namespace std;

int isGreater(UnlimitedInt *n1, UnlimitedInt *n2)
{
    if (n1->get_size() > n2->get_size())
    {
        return 1; // greater than
    }
    else if (n1->get_size() < n2->get_size())
    {
        return 0; // less than
    }

    int *n1_u = n1->get_array();
    int *n2_u = n2->get_array();
    for (int i = 0; i < n1->get_size(); i++)
    {
        if (n1_u[i] > n2_u[i])
        {
            return 1; // greater than
        }
        else if (n1_u[i] < n2_u[i])
        {
            return 0; // less than
        }
    }
    return -1; // equal
}

UnlimitedInt::UnlimitedInt()
{
    size = 1;
    sign = 0;
    capacity = 1;
    unlimited_int = new int[1];
    unlimited_int[0] = 0;
}

UnlimitedInt::UnlimitedInt(string s)
{
    if (s[0] == '-')
    {
        sign = -1;
        size = s.size() - 1;
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 1; i < s.size(); i++)
        {
            unlimited_int[i - 1] = (int)s[i] - 48;
        }
    }
    else
    {
        sign = 1;
        size = s.size();
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 0; i < size; i++)
        {
            unlimited_int[i] = (int)s[i] - 48;
        }
    }
}

UnlimitedInt::UnlimitedInt(int i) // can be improved, use no temps
{
    int temp;
    size = 0;
    if (i < 0)
    {
        sign = -1;
        i = -1 * i;
        temp = i;
    }
    else
    {
        sign = 1;
        temp = i;
    }

    while (temp > 0)
    {
        size += 1;
        temp /= 10;
    }

    capacity = size;
    unlimited_int = new int[size];
    int temp_arr[size];
    int idx = 0;

    while (i > 0)
    {
        int num = i % 10;
        temp_arr[idx] = num;
        i /= 10;
        idx++;
    }

    for (int i = 0; i < size; i++)
    {
        unlimited_int[i] = temp_arr[size - i - 1];
    }
}

UnlimitedInt::UnlimitedInt(int *ulimited_int, int cap, int sgn, int sz)
{
    capacity = cap;
    size = sz;
    sign = sgn;
    unlimited_int = new int[size];

    for (int i = 0; i < size; i++)
    {
        unlimited_int[i] = ulimited_int[i];
    }
}

int UnlimitedInt::get_size()
{
    return size;
}

int *UnlimitedInt::get_array()
{
    return unlimited_int;
}

int UnlimitedInt::get_sign()
{
    return sign;
}

int UnlimitedInt::get_capacity()
{
    return capacity;
}

UnlimitedInt::~UnlimitedInt()
{
    delete[] unlimited_int;
}

UnlimitedInt *UnlimitedInt::add(UnlimitedInt *i1, UnlimitedInt *i2) // store in the curr unlimited_int, not the way done her, leading zeros not handled, and hence size and capacity can be wrong
{
    UnlimitedInt *i_2 = new UnlimitedInt(i2->get_array(), i2->get_capacity(), i2->get_sign(), i2->get_size());
    UnlimitedInt *i_1 = new UnlimitedInt(i1->get_array(), i1->get_capacity(), i1->get_sign(), i1->get_size());
    UnlimitedInt *new_n = new UnlimitedInt();
    if (i_1->get_sign() == -1 and i_2->get_sign() == 1)
    {

        // perform subtraction
        int i1_size = i_1->get_size();
        int i2_size = i_2->get_size();

        if (i1_size < i2_size)
        {
            new_n->sign = 1;
            new_n->size = i2_size + 1;
            new_n->capacity = new_n->size;
            new_n->unlimited_int = new int[new_n->size];
            for (int i = 0; i < new_n->size; i++)
            {
                new_n->unlimited_int[i] = 0;
            }

            int *temp = i_2->get_array();
            for (int i = 0; i < i2_size; i++)
            {
                new_n->unlimited_int[new_n->size - 1 - i] = temp[i2_size - i - 1];
            }
            temp = i_1->get_array();
            for (int i = 0; i < i2_size; i++)
            {

                if (i < i1_size)
                {
                    new_n->unlimited_int[new_n->size - i - 1] -= temp[i1_size - i - 1];
                    if (new_n->unlimited_int[new_n->size - i - 1] < 0)
                    {
                        new_n->unlimited_int[new_n->size - i - 1] += 10;
                        new_n->unlimited_int[new_n->size - i - 2] -= 1;
                    }
                }
                else
                {
                    if (new_n->unlimited_int[new_n->size - i - 1] < 0 && new_n->size - i - 2 >= 0)
                    {
                        new_n->unlimited_int[new_n->size - i - 1] += 10;
                        new_n->unlimited_int[new_n->size - i - 2] -= 1;
                    }
                }
            }
            delete temp;
        }
        else if (i1_size > i2_size) // handle deletes
        {
            UnlimitedInt *Newi_2 = new UnlimitedInt(i2->get_array(), i2->get_capacity(), -1 * i2->get_sign(), i2->get_size());
            UnlimitedInt *Newi_1 = new UnlimitedInt(i1->get_array(), i1->get_capacity(), -1 * i1->get_sign(), i1->get_size());
            new_n = add(Newi_1, Newi_2);
            delete Newi_1;
            delete Newi_2;
            new_n->sign *= -1;
            return new_n;
        }
        else
        {
            if (isGreater(i_1, i_2) == -1)
            {
                new_n->size = 1;
                new_n->unlimited_int = new int[1];
                new_n->unlimited_int[0] = 0;
                new_n->sign = 0;
                new_n->capacity = 1;
            }
            if (isGreater(i_1, i_2) == 1)
            {
                UnlimitedInt *Newi_2 = new UnlimitedInt(i2->get_array(), i2->get_capacity(), -1 * i2->get_sign(), i2->get_size());
                UnlimitedInt *Newi_1 = new UnlimitedInt(i1->get_array(), i1->get_capacity(), -1 * i1->get_sign(), i1->get_size());
                new_n = add(Newi_1, Newi_2);
                delete Newi_1;
                delete Newi_2;
                new_n->sign *= -1;
                return new_n;
            }
            if (isGreater(i_1, i_2) == 0)
            {
                new_n->size = i1_size + 1;
                new_n->capacity = new_n->size;
                new_n->unlimited_int = new int[new_n->size];
                for (int i = 0; i < new_n->size; i++)
                {
                    new_n->unlimited_int[i] = 0;
                }

                int *temp = i_2->get_array();
                for (int i = 0; i < i2_size; i++)
                {
                    new_n->unlimited_int[new_n->size - 1 - i] = temp[i2_size - i - 1];
                }
                temp = i_1->get_array();
                for (int i = 0; i < i1_size; i++)
                {
                    new_n->unlimited_int[new_n->size - i - 1] -= temp[i1_size - i - 1];
                    if (new_n->unlimited_int[new_n->size - i - 1] < 0 && new_n->unlimited_int[new_n->size - i - 2] - 1 >= 0)
                    {
                        new_n->unlimited_int[new_n->size - i - 1] += 10;
                        new_n->unlimited_int[new_n->size - i - 2] -= 1;
                    }
                    else if (new_n->unlimited_int[new_n->size - i - 1] < 0)
                    {
                        new_n->unlimited_int[new_n->size - i - 1] *= -1;
                        break;
                    }
                }
                delete temp;

                new_n->sign = 1;
            }
        }

        int i = 0;
        while (new_n->unlimited_int[i] == 0)
        {
            i++;
        }

        if (i > 0)
        {
            new_n->size -= i;
            if (new_n->size < 0)
            {
                new_n->size = 0;
            }
            new_n->capacity -= i;
            int *new_arr = new int[new_n->size];
            for (int j = 0; j < new_n->size; j++)
            {
                new_arr[j] = new_n->unlimited_int[j + i];
            }

            delete[] new_n->unlimited_int;

            new_n->unlimited_int = new_arr;
        }

        return new_n;
    }
    else if (i_1->get_sign() == 1 and i_2->get_sign() == -1)
    {
        return add(i_2, i_1);
    }
    else if (i_1->get_sign() == -1 and i_2->get_sign() == -1)
    {

        // part 3
        new_n->sign = -1;

        // perform addition
        int i1_size = i_1->get_size();
        int i2_size = i_2->get_size();

        if (i1_size >= i2_size)
        {
            new_n->size = i1_size + 1;
            new_n->capacity = new_n->size;
            new_n->unlimited_int = new int[new_n->size];
            new_n->unlimited_int[0] = 0;

            int *temp = i_1->get_array();
            for (int i = 0; i < i1_size; i++)
            {
                new_n->unlimited_int[i + 1] = temp[i];
            }
            temp = i_2->get_array();
            for (int i = 0; i < i2_size; i++)
            {
                new_n->unlimited_int[new_n->size - i - 1] += temp[i2_size - i - 1];
                if (new_n->unlimited_int[new_n->size - i - 1] > 9)
                {
                    new_n->unlimited_int[new_n->size - i - 1] %= 10;
                    new_n->unlimited_int[new_n->size - i - 2] += 1;
                }
            }
            delete temp;
        }

        else
        {
            new_n->size = i2_size + 1;
            new_n->capacity = new_n->size;
            new_n->unlimited_int = new int[new_n->size];
            new_n->unlimited_int[0] = 0;

            int *temp = i_2->get_array();
            for (int i = 0; i < i2_size; i++)
            {
                new_n->unlimited_int[i + 1] = temp[i];
            }
            temp = i_1->get_array();
            for (int i = 0; i < i1_size; i++)
            {
                new_n->unlimited_int[new_n->size - i - 1] += temp[i1_size - i - 1];
                if (new_n->unlimited_int[new_n->size - i - 1] > 9)
                {
                    new_n->unlimited_int[new_n->size - i - 1] %= 10;
                    new_n->unlimited_int[new_n->size - i - 2] += 1;
                }
            }
            delete temp;
        }
        return new_n;
    }
    else
    {

        // part 3
        new_n->sign = 1;

        // perform addition
        int i1_size = i_1->get_size();
        int i2_size = i_2->get_size();

        if (i1_size >= i2_size)
        {
            new_n->size = i1_size + 1;
            new_n->capacity = new_n->size;
            new_n->unlimited_int = new int[new_n->size];
            new_n->unlimited_int[0] = 0;

            int *temp = i_1->get_array();
            for (int i = 0; i < i1_size; i++)
            {
                new_n->unlimited_int[i + 1] = temp[i];
            }

            delete temp;

            temp = i_2->get_array();
            for (int i = 0; i < i2_size; i++)
            {
                new_n->unlimited_int[new_n->size - i - 1] += temp[i2_size - i - 1];
                if (new_n->unlimited_int[new_n->size - i - 1] > 9)
                {
                    new_n->unlimited_int[new_n->size - i - 1] %= 10;
                    new_n->unlimited_int[new_n->size - i - 2] += 1;
                }
            }
            delete temp;
        }

        else
        {
            new_n->size = i2_size + 1;
            new_n->capacity = new_n->size;
            new_n->unlimited_int = new int[new_n->size];
            new_n->unlimited_int[0] = 0;

            int *temp = i_2->get_array();
            for (int i = 0; i < i2_size; i++)
            {
                new_n->unlimited_int[i + 1] = temp[i];
            }

            delete temp;

            temp = i_1->get_array();
            for (int i = 0; i < i1_size; i++)
            {
                new_n->unlimited_int[new_n->size - i - 1] += temp[i1_size - i - 1];
                if (new_n->unlimited_int[new_n->size - i - 1] > 9)
                {
                    new_n->unlimited_int[new_n->size - i - 1] %= 10;
                    new_n->unlimited_int[new_n->size - i - 2] += 1;
                }
            }
            delete temp;
        }
        return new_n;
    }
    return new_n;
}

UnlimitedInt *UnlimitedInt::sub(UnlimitedInt *i1, UnlimitedInt *i2) // to be tested, also when the result is 0, sign <- 0, delete temp poiniterrs
{
    UnlimitedInt *new_i2 = new UnlimitedInt(i2->unlimited_int, i2->capacity, -1 * i2->sign, i2->size);
    UnlimitedInt *new_i1 = new UnlimitedInt(i1->unlimited_int, i1->capacity, i1->sign, i1->size);
    UnlimitedInt *new_n = add(new_i1, new_i2);
    return new_n;
}

UnlimitedInt *UnlimitedInt::mul(UnlimitedInt *i1, UnlimitedInt *i2) // bt regarding actual length of the string, same with all the other arithmetic funcctions
{
    if ((i1->get_sign() == -1 and i2->get_sign() == 1) or (i1->get_sign() == 1 and i2->get_sign() == -1)) // manage deletion of the pouiter
    {
        UnlimitedInt *new_n = new UnlimitedInt();

        new_n->sign = -1;

        int i1_size = i1->get_size();
        int i2_size = i2->get_size();

        new_n->size = i1_size + i2_size;
        new_n->capacity = new_n->size;
        new_n->unlimited_int = new int[new_n->size];

        int *num1 = i1->get_array();
        int *num2 = i2->get_array();

        for (int i = 0; i < new_n->size; i++)
        {
            new_n->unlimited_int[i] = 0;
        }

        for (int i = i1_size - 1; i >= 0; i--)
        {
            for (int j = i2_size - 1; j >= 0; j--)
            {
                int temp = num1[i] * num2[j];
                new_n->unlimited_int[i + j + 1] += temp;
            }
        }

        for (int i = new_n->size - 1; i > 0; i--)
        {
            if (new_n->unlimited_int[i] >= 10)
            {
                new_n->unlimited_int[i - 1] += new_n->unlimited_int[i] / 10;
                new_n->unlimited_int[i] %= 10;
            }
        }

        return new_n;
    }
    else
    {
        UnlimitedInt *new_n = new UnlimitedInt();

        new_n->sign = 1;

        int i1_size = i1->get_size();
        int i2_size = i2->get_size();

        new_n->size = i1_size + i2_size;
        new_n->capacity = new_n->size;
        new_n->unlimited_int = new int[new_n->size];

        int *num1 = i1->get_array();
        int *num2 = i2->get_array();

        for (int i = 0; i < new_n->size; i++)
        {
            new_n->unlimited_int[i] = 0;
        }

        for (int i = i1_size - 1; i >= 0; i--)
        {
            for (int j = i2_size - 1; j >= 0; j--)
            {
                int temp = num1[i] * num2[j];
                new_n->unlimited_int[i + j + 1] += temp;
            }
        }

        for (int i = new_n->size - 1; i > 0; i--)
        {
            if (new_n->unlimited_int[i] >= 10)
            {
                new_n->unlimited_int[i - 1] += new_n->unlimited_int[i] / 10;
                new_n->unlimited_int[i] %= 10;
            }
        }
        return new_n;
    }
}

UnlimitedInt *UnlimitedInt::div(UnlimitedInt *i1, UnlimitedInt *i2) // change everything here
{
    UnlimitedInt *one = new UnlimitedInt(1);
    if (isGreater(i2, i1) == 1)
    {
        UnlimitedInt *zero = new UnlimitedInt(0);
        return zero;
    }
    else if (isGreater(i2, i1) == -1)
    {
        UnlimitedInt *result = one;
        result->sign = (i1->get_sign() * i2->get_sign());
        return result;
    }
    UnlimitedInt *result = new UnlimitedInt();
    UnlimitedInt *dividend = new UnlimitedInt(i1->unlimited_int, i1->capacity, 1, i1->size);
    UnlimitedInt *divisor = new UnlimitedInt(i2->unlimited_int, i2->capacity, 1, i2->size);
    // UnlimitedInt *t_rex = new UnlimitedInt();

    while (sub(dividend, divisor)->sign > 0)
    {
        // t_rex = sub(dividend, divisor);
        // dividend = new UnlimitedInt(t_rex->unlimited_int, t_rex->capacity, t_rex->sign, t_rex->size);
        dividend = sub(dividend, divisor);
        result = add(result, one);
    }

    if ((i1->sign) * (i2->sign) == -1 && sub(dividend, divisor)->sign == -1)
    {
        result = add(result, one);
    }

    if (sub(dividend, divisor)->sign == 0)
    {
        result = add(result, one);
    }

    result->sign = (i1->sign) * (i2->sign);
    return result;
}

UnlimitedInt *UnlimitedInt::mod(UnlimitedInt *i1, UnlimitedInt *i2)
{
    // again no idea about this one
}

string UnlimitedInt::to_string()
{
    string result = "";
    for (int i = 0; i < size; i++)
    {
        result.push_back('0' + unlimited_int[i]);
    }
    int pos = 0;
    while (pos < result.size() && result[pos] == '0')
    {
        pos++;
    }

    if (pos == result.size())
    {
        return "0";
    }

    result = result.substr(pos, result.size() - pos);

    if (sign == -1)
    {
        result.insert(result.begin(), '-');
    }
    return result;
}
