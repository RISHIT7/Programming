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
    int st = 0, en = 0, sum = 0, maxSum = INT_MIN;
    for (st =0; st<n;st++)
    {
        for (en = 0; en < n; en++)
        {
            for (int i = st; i < en; i++)
            {
                sum += arr[i];
            }cout<<endl;
            maxSum = max(maxSum, sum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}
// BruteForce and O(N^3) which is very bad