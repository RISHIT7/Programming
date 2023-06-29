#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int N = 10;
        int check[N];
        for (int i = 0; i < N; i++)
        {
            check[i] = false;
        }
        for (int i = 0; i < N; i++)
        {
            if (a[i] >= 1)
            {
                check[a[i] - 1] = true;
            }
        }
        for (int i = 0; i < N; i++)
        {
            cout << check[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            if (check[i] == false)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}