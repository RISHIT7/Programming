#include <iostream>
using namespace std;

int sumSubArray(int arr[], int n)
{
    int s, e;
    cout<<"The start index and end index is"<<endl;
    cin>>s>>e;
    int sum = 0;
    for (int i = s; i <= e; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;
    cout<<"The number  of elements are ";
    cin>>n;
    int arr[n];
    cout<<"The elements are"<<endl;
    for (int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int k = sumSubArray(arr, n);
    cout<<"The sum of subarray is " <<k <<endl;
    return 0;
}