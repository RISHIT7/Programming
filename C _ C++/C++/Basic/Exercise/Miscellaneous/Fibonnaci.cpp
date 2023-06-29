#include <iostream>
using namespace std;

int get_fib(int a, int b, int i, int n){
    int c = a+b;
    if (i < n){
        i += 1;
        get_fib(b, c, i, n);
        cout<<c<<endl;
    }
    return c;
}

int main(){
    int a, b, c, i, n;
    i = 0;
    cin>>n;
    a = 0;
    b = 1;
    c = get_fib(a, b, i, n-2);
    cout<<c<<endl;
    cout<<0<<endl;
    return 0;
}