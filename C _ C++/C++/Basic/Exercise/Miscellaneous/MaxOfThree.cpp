#include <iostream>
using namespace std;

int main()
{
    int max, a;
    cout << "Enter the first value ";
    cin >> a;

    int b;
    cout << "Enter the scond value ";
    cin >> b;

    int c;
    cout << "Enter the third value ";
    cin >> c;
    cout << "The biggest value is ";
    if (a > b)
    {
        if (a > c)
        {
            cout << a;
        }
        else
        {
            cout << c;
        }
    }
    else
    {
        if (b > c)
        {
            cout << b;
        }
        else
        {
            cout << c;
        }
    }
    return 0;
}