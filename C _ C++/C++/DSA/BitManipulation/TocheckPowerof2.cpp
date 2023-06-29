// n = 101 or 1000
// n-1 = like swaping the rightmost number and thereafter
// n-1 = 100 or 0111
// taking & of both bits => 100, 0000
// powers of 2 will always result in a 0 value!

#include <iostream>
using namespace std;

int getBit(int n)
{
    return (n & !(n & n - 1));
}

int main()
{
    int n;
    cin >> n;
    int k = getBit(n);
    cout << k << endl;
    return 0;
}