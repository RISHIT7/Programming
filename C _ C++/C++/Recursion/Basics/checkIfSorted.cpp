#include <iostream>
using namespace std;

bool check(int arr[], int i, int n)
{
    if (i < n)
    {
        if (i + 1 < n && arr[i + 1] > arr[i])
        {
            check(arr, i + 1, n);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << check(arr, 0, n) << endl;
    return 0;
}