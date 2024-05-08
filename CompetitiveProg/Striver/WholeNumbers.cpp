#include <iostream>
#include <vector>
using namespace std;

void solve(long int n)
{
    long int mul = 1;
    vector<long int> res;
    while (n > 0)
    {
        int val = n % 10;
        res.push_back(val * mul);
        mul *= 10;
        n /= 10;
    }
    for (long unsigned int i = 0; i < res.size(); i++)
    {
        if (res[i] == 0)
        {
            res.erase(res.begin() + i);
            i--;
        }
    }
    cout << res.size() << endl;
    for (long unsigned int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        solve(n);
    }
}