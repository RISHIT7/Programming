#include <iostream>
using namespace std;

//// Solution 1 ////

// void LASa()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int A[n - 1];
//     for (int i = 0; i < n - 1; i++)
//     {
//         A[i] = (arr[i] - arr[i + 1]);
//     }
//     int B[n - 1];
//     for (int i = 0; i < n - 1; i++)
//     {
//         int k = 0;
//         for (int j = i; j < n - 1; j++)
//         {
//             if (A[i] == A[j])
//             {
//                 k += 1;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         B[i] = k;
//     }
//     int m = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (m < B[i])
//         {
//             m = B[i];
//         }
//     }
//     cout << m+2 << endl;
// }

// int main()
// {
//     int tc;
//     cin >> tc;
//     for (int i = 0; i < tc; i++)
//     {
//         LASa();
//     }
//     return 0;
// }

//// Solution 2 ////

int main()
{
    // Getting the number of elements
    int n;
    cin >> n;

    // Getting all the elements
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Magic
    int ans = 2;
    int d = a[1] - a[0];
    int j = 2;
    int curr = 2;
    while (j < n)
    {
        if (a[j] - a[j - 1] == d)
            curr++;
        else
        {
            d = a[j] - a[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }

    // The bunny comes out
    cout << ans << endl;
    return 0;
}