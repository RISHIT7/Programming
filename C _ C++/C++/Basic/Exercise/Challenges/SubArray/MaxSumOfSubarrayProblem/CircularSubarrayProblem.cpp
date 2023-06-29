#include <iostream>
using namespace std;
// max sub = total - sum of non contributing elements
// to find non contributing, reverse sign and apply kadane's alg

int kadanes(int arr[], int n)
{
    int maxsum = INT_MIN, currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum > 0)
        {
            maxsum = max(currsum, maxsum);
        }
        else
        {
            currsum = 0;
        }
    }
    return maxsum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int wrapsum;
    int nonwrapsum;
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += a[i];
        a[i] = -a[i];
    }
    nonwrapsum = kadanes(a, n);
    wrapsum = totalsum + kadanes(a, n);
    cout << max(wrapsum, nonwrapsum) << endl;
    return 0;
}