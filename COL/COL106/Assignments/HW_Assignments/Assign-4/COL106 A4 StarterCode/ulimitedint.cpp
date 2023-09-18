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



int main()
{
    UnlimitedInt *num_str = new UnlimitedInt("-1234567812345678");
    UnlimitedInt *num_int = new UnlimitedInt(12345678);
    cout << num_str->get_size() << endl;
    cout << num_str->get_sign() << endl;
    cout << num_int->get_size() << endl;
    cout << num_int->get_sign() << endl;
    return EXIT_SUCCESS;
}
