#include <iostream>
using namespace std;

int main()
{
    int d = 2;
    cout << "Welcome to a program with a bug !\n";
    cin >> d;
    cout << "You gave me: " << d << "\n";
    int count = 0;
    while (d < 100)
    {
        d++;
        count++;
    }
    cout << "Value of count is " << count << "\n";

    return 0;
}