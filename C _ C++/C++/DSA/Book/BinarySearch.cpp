#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // Implementation 1
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int a = 0, b = size(v) - 1, x = 3;
    while (a <= b)
    {
        int k = (a + b / 2);
        if (v[k] == x)
        {
            cout << k << endl;
            break;
        }
        if (v[k] > x)
        {
            b = k - 1;
        }
        else
        {
            a = k + 1;
        }
    }
    // Implementation 2
    int l = 0;
    for (int b = size(v) / 2; b >= 1; b /= 2)
    {
        while (l + b < size(v) && v[l + b] <= x)
        {
            l += b;
        }
    }
    if (v[l] == x)
    {
        cout << l << endl;
    }

    return 0;
}