#include <iostream>
#include <algorithm>

bool isFeasible(int mid, int arr, int n, int k)
{
    int pos = arr[0], elements = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int result = -1;
    int left = 1, right = n - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (idFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

int main()
{

    return 0;
}