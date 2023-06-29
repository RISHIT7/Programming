#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int c;
        cin >> c;
        long long int fc = 0;
        if (c > 250000)
        {
            c -= 250000;
            fc += 250000;
        }
        else
        {
            fc += c;
            c = 0;
        }
        if (c > 250000)
        {
            c -= 250000;
            fc += 0.95 * 250000;
        }
        else
        {
            fc += 0.95 * c;
            c = 0;
        }
        if (c > 250000)
        {
            c -= 250000;
            fc += 0.9 * 250000;
        }
        else
        {
            fc += 0.9 * c;
            c = 0;
        }
        if (c > 250000)
        {
            c -= 250000;
            fc += 0.85 * 250000;
        }
        else
        {
            fc += 0.85 * c;
            c = 0;
        }
        if (c > 250000)
        {
            c -= 250000;
            fc += 0.8 * 250000;
        }
        else
        {
            fc += 0.8 * c;
            c = 0;
        }
        if (c > 250000)
        {
            c -= 250000;
            fc += 0.75 * 250000;
        }
        else
        {
            fc += 0.75 * c;
            c = 0;
        }
        if (c > 250000)
        {
            c -= 250000;
            fc += 0.7 * 250000;
        }
        fc += 0.7*c;
        c = 0;
        cout << fc << endl;
    }
    return 0;
}