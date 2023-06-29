#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;

    for (int i = 3; i <= 2022; i++)
    {
        double k = (15 * (pow(i, 2)) + (14 * i) + 3) / 4;
        double m = sqrt(k);
        if (remainder(m, 10) == 0)
        {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}