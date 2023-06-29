#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        string s;
        cin>>s;
        long long int value = 0, count = 0;
        for (long long int i = n-1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                value += pow(2, count);
            }
            count += 1;
        }
        long long int y, min = value;
        for (long long int i = 1; i <= n; i++)
        {
            long long int temp = value/pow(2, i);
            long long int tem = value^temp;
            if (min >= tem)
            {
                min = tem;
                y = i;
            }
        }
        cout<<y<<endl;
    }
    return 0;
}