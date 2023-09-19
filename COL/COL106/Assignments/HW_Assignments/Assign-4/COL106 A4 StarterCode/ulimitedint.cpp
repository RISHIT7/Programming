/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"
#include <iostream>
using namespace std;

UnlimitedInt::UnlimitedInt()
{
    size = 0;
    sign = 0;
    capacity = 0;
    unlimited_int = {};
}

UnlimitedInt::UnlimitedInt(string s)
{
    if (s[0] == '-')
    {
        sign = -1;
        size = s.size() - 1;
        capacity = size;
        unlimited_int = new int[size];
        for (int i = 1; i < size; i++)
        {
            unlimited_int[i - 1] = (int)s[i];
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
            unlimited_int[i] = (int)s[i];
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
    }

    for (int i = 0; i < size; i++)
    {
        unlimited_int[i] = temp_arr[size - i - 1];
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

UnlimitedInt::~UnlimitedInt()
{
    delete[] unlimited_int;
}

UnlimitedInt *UnlimitedInt::add(UnlimitedInt *i1, UnlimitedInt *i2) // store in the curr unlimited_int, not the way done here
{
    if (i1->get_sign() == -1 and i2->get_sign() == 1)
    {
        // part 1
    }
    else if (i2->get_sign() == -1 and i2->get_sign() == 1)
    {
        // part 2
    }
    else if (i1->get_sign() == -1 and i2->get_sign() == -1)
    {
        // part 3
    }
    else
    {
        // part 4
    }
}

UnlimitedInt *UnlimitedInt::sub(UnlimitedInt *i1, UnlimitedInt *i2)
{
    i2->sign = -1;
    unlimited_int = (i1, i2);
    return unlimited_int;
}

UnlimitedInt *UnlimitedInt::mul(UnlimitedInt *i1, UnlimitedInt *i2)
{
    if ((i1->get_sign() == -1 and i2->get_sign() == 1) or (i1->get_sign() == 1 and i2->get_sign() == -1))
    {
        // part 1
    }
    else
    {
        // part 2
    }
}

UnlimitedInt *UnlimitedInt::div(UnlimitedInt *i1, UnlimitedInt *i2)
{
    // no idea about this one
}

UnlimitedInt *UnlimitedInt::mod(UnlimitedInt *i1, UnlimitedInt *i2)
{
    // again no idea about this one
}

string UnlimitedInt::to_string()
{
    string result = "";
    if (sign = -1)
    {
        result.append("-");
    }
    for (int i = 0; i < size; i++)
    {
        result.append(unlimited_int[i]);
    }
    return result;
}

int main()
{
    UnlimitedInt *num_str = new UnlimitedInt("-1234567812345678");
    // UnlimitedInt *num_int = new UnlimitedInt(12345678);
    cout << num_str->get_size() << endl;
    cout << num_str->get_sign() << endl;
    // cout << num_int->get_size() << endl;
    // cout << num_int->get_sign() << endl;
    UnlimitedInt *num_str_1 = new UnlimitedInt("1234567812345678");

    num_str->add(num_str, num_str_1);
    cout << num_str->get_sign() << endl;
    return EXIT_SUCCESS;
}
