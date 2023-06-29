#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int arr[N], motu = 0, tomu = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            if (i % 2 == 0)
            {
                motu += arr[i];
            }
            else
            {
                tomu += arr[i];
            }
        }
        for (int i = 0; i < K; i++)
        {
            int k, Max = INT_MIN;
            for (int j = 0; j < N; j++)
            {
                if (Max < arr[j])
                {
                    Max = arr[j];
                    k = j;
                }
            }
            motu -= Max;
            tomu += Max;
            arr[k] = INT_MIN;
        }
        if (motu >= tomu)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}