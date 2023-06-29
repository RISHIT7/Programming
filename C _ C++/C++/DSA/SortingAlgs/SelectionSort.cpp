#include <iostream>
#include <climits>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == min)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
    selectionSort(arr, n);
    return 0;
}