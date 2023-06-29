#include <iostream>
using namespace std;

int maxTilli(int arr[], int n)
{
    int j;
    cin>>j;
    int min;
    for (int i = 0; i < j; i++)
    {
        if (min > arr[j])
        {
            min = arr[j];
        }
    }
    return min;
}

int main()
{
    int n;
    cout<<"The number of elements is: ";
    cin>>n;
    int arr[n];
    cout<<"The elements are"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k = maxTilli(arr, n);
    cout<<"The max till "<< k <<endl;
    return 0;
}