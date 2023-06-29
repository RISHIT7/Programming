#include <iostream>
using namespace std;
// 137 = 1*8^2 + 3*8 + 7
//     = 64 + 24 + 7
//     = 95

// 105 = 1*64 + 5*8 + 1
//     = 151

// 150 = 1*64 + 5*8 + 0
//     = 104

int get_decimal(int n)
{
    int result, i;
    result = 0;
    i = 1;
    while (n / 10 != 0)
    {
        result += n % 10 * i;
        i *= 8;
        n -= n % 10;
        n /= 10;
    }
    result += n % 10 * i;
    return result;
}

int get_octal(int n)
{
    int result, i;
    result = 0;
    i = 1;
    while (n / 8 != 0)
    {
        result += n % 8 * i;
        i *= 10;
        n -= n % 8;
        n /= 8;
    }
    result += n % 8 * i;
    return result;
}

int main()
{
    int n;
    cin >> n;
    char per;
    cin >> per;
    if (per == 'd')
    {
        cout << get_decimal(n);
    }
    else if (per == 'o')
    {
        cout << get_octal(n);
    }
    else
    {
        cout << get_decimal(n);
        cout << get_octal(n);
    }
    return 0;
}