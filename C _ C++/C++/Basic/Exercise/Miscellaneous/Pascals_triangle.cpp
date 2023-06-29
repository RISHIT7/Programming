#include <iostream>
using namespace std;

int get_fact(int n){
    int res1 = 1;
    for (int i = n; i >= 1; i--)
    {
        res1 *= i;
    }
    return res1;
}

int get_comb(int i, int j){
    int res2;
    res2 = get_fact(i)/(get_fact(j)*get_fact(i-j));
    return res2;
}

int main()
{
    int n, k;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<get_comb(i, j);
        }
        cout<<endl;
    }
    
    return 0;
}