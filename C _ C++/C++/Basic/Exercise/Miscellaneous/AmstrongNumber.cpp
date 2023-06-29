#include <iostream>
using namespace std;

int check(int n)
{
    int sum = 0;
    while (n >= 1)
    {
        int k = n % 10;
        n -= k;
        n /= 10;
        sum += k*k*k;
    }
    return sum;
}

int main()
{
    int n, m;
    cin >> n;
    m = check(n);
    if (m == n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}