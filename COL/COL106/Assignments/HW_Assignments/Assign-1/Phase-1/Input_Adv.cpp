#include <iostream>
using namespace std;

int main()
{
    int a, b, c = 0;
    while ((cin >> a >> b))
    {
        if (a == 6 || a == 9)
        {
            cout << a << " " << b << endl;
        }
        else
        {
            cin >> c;
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}