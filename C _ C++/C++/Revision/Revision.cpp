#include <iostream>
using namespace std;

int main()
{
    int d = 2;
    cout << "Welcome to a program with a bug !\n";
    cin >> d;
    cout << "You gave me: " << d << "\n";

    return 0;
}