#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            a[i] = temp;
        }
        int i, j = 0;
        while (i != n - 1 & j != n - 1)
        {
            int sum = s;
            for (int k = i; k <= j; k++)
            {
                sum -= a[k];
            }
            if (sum == 0)
            {
                cout << i << " " << j << endl;
                break;
            }
            else if (sum < 0)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        if (i == j)
        {
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}