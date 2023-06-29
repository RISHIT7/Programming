#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a * a + b * b - c * c == 0)
    {
        cout << "YES" << endl;
    }
    else if (a * a + c * c - b * b == 0)
    {
        cout << "YES" << endl;
    }
    else if (b * b + c * c - a * a == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}