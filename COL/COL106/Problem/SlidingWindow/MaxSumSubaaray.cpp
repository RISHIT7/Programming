#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[], int X, int K, int n)
{
    int ans = 0, Max = 0;
    for (int i = 0; i < K; i++)
    {
        Max += arr[i];
    }
    ans = Max;
    for (int i = K; i < n; i++)
    {
        Max = Max - arr[i - K] + arr[i];
        if (Max < X)
        {
            ans = max(ans, Max);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int K = 3;
    int X = 20;
    cout << maxSumSubarray(arr, X, K, 6) << endl;
    return 0;
}