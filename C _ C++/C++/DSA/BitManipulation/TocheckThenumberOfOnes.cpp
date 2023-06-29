#include <iostream>
using namespace std;

void check(int a)
{
    int counter = 0;
    while (a != 0)
    {
        a = a & (a - 1);
        counter += 1;
    }
    cout << counter << endl;
}

int main()
{
    int n;
    cin >> n;
    check(n);
    return 0;
}