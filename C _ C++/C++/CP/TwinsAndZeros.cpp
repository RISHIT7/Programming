#include <iostream>
#include <cmath>
using namespace std;

int cal_n(int n){
   int temp = 1;
   for (int i = 2; i <= n; i++)
      temp = temp * i;
   return temp;
}

int nCr(int n, int r){
   return cal_n(n) / (cal_n(r) * cal_n(n - r));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int count = 0;
        for (int n = 1; n <= N; n++)
        {
            for (int m = 0; m <= n; m++)
            {
                if (((n - m) % 3 == 0) && (m <= M))
                {
                    count += nCr(N, n) * nCr(M, m);
                    cout<<n<<" "<<m<<endl;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}