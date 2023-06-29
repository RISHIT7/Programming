#include <iostream>
using namespace std;

int linearSearch(int arr[], int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
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
    cout<<linearSearch(arr, target, n)<<endl;
    return 0;
}