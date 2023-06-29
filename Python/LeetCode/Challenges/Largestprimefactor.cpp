#include <bits/stdc++.h>

using namespace std;
#define lli long long int


int main(){
    lli n = 600851475142, m;
    for (lli j = 1; j <= n/2; j++)
    {
        if (n%j == 0)
        {
            m = max(m, j);
        }
    }
    cout << m;
    return 0;
}