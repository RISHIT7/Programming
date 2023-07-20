#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double a, b;
        cin >> a >> b;
        double c = (a + b) / 2.0;
        if (floor(c) == c and ceil(c) == c)
        {
            cout << c << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}