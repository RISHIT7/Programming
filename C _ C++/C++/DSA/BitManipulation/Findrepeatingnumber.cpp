#include <iostream>
using namespace std;

int setBit(int n, int pos)
{
    return (n & (1<<pos))!= 0;
}

void unique2(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum^arr[i];
    }
    int setbit =0, pos=0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int new_xor = 0;
    for (int i = 0; i < n; i++)
    {
        if(setBit(arr[i], pos-1))
        {
            new_xor = new_xor^arr[i]; 
        }
    }
    
}

int unique(int arr[], int n)
{
    // unique SINGLE element
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}

int main()
{
    int arr[] = {1, 2, 4, 1, 2};
    cout<<unique(arr, 5)<<endl;
    int A[] = {1, 2, 3, 4, 3, 1};
    unique2(A, 6);
    return 0;
}