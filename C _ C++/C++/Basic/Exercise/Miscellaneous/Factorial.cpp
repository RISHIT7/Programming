#include <iostream>
using namespace std;

int get_fact(int n, int a)
{
    if (n - 1 > 0)
    {
        a *= n;
        get_fact(n - 1, a);
    }
    else if (n == 1)
    {
        cout << a << endl;
    }
    return a;
}

int main()
{
    int n, a;
    cin >> n;
    a = 1;
    get_fact(n, a);
    return 0;
}