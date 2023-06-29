#include <iostream>
using namespace std;

int check(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i+1 == n-1) && (arr[i] < arr[i+1]))
        {
            cout<<"if"<<i<<endl;
            max += 1;
        }
        else if ((i+1 < n-1) && (i-1 >= 0) && (arr[i-1] < arr[i]) && (arr[i] > arr[i+1]))
        {
            cout<<"elif"<<i<<endl;
            max += 1;
        }
        else{
            cout<<"else"<<i<<endl;
        }
    }
    return max;
}

void RBDa()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int res = check(arr, n);
    cout<<res<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    RBDa();
    return 0;
}