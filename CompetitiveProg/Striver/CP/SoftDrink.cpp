#include <iostream>
using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int ml = k*l;
    int slices = c*d;
    int salt = p;

    int ml_num = ml / nl;
    int slices_num = slices;
    int salt_num = salt / np;

    cout << min(ml_num, min(slices_num, salt_num))/n << endl;
}