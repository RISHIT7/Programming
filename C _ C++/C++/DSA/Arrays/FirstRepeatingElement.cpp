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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int N = 9999; // my laptop's cap
        int idx[N];
        for (int i = 0; i < N; i++)
        {
            idx[i] = -1;
        }
        int minidx = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (idx[arr[i]] != -1)
            {
                minidx = min(minidx, idx[arr[i]]);
            }
            else
            {
                idx[arr[i]] = i;
            }
        }
        if (minidx == INT_MAX)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << arr[minidx] << endl;
        }
    }
    return 0;
}