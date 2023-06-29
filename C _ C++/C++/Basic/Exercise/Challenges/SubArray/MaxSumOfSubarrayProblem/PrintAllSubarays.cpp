#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int st = 0, en = 0;
    for (st =0; st<n;st++)
    {
        for (en = 0; en < n; en++)
        {
            for (int i = st; i < en; i++)
            {
                cout<<arr[i];
            }
        }
    }
    return 0;
}