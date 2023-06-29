#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n], target;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> target;
    cout << binarySearch(arr, n, target) << endl;
    return 0;
}