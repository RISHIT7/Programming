#include <iostream>
using namespace std;

void solve(string s)
{
    long long int n = stoll(s);
    long long int ans = 0;
    long long int mul = 1;
    while (n >= 10)
    {
        int val = n % 10;
        n /= 10;

        if (val > 4)
        {
            val = 9 - val;
        }

        ans += (val * mul);
        mul *= 10;
    }
    int val = n % 10;
    if (val > 4 && val != 9)
    {
        val = 9 - val;
    }

    cout << ans + (mul * val) << endl;
}

int main()
{
    string s;
    cin >> s;
    solve(s);
    return 0;
}