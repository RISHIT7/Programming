#include <iostream>
using namespace std;

int get_fact(int n, int b){
    b *= n;
    n -= 1;
    if (n-1>0){
        get_fact(n, b);
    }
    else if(n == 1){
        return b;
    }
}

int get_comb(int n, int m){
    int nfact, mfact, nmfact, C;
    nfact = get_fact(n, 1);
    mfact = get_fact(m, 1);
    nmfact = get_fact(n-m, 1);
    C = nfact/(mfact*nmfact);
    cout<<C<<endl;
    return C;
}

int main()
{
    int n, m;
    cin>>n>>m;
    get_comb(n, m);
    return 0;
}