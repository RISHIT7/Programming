#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int change_mod(int curr, int req)
{
    int m1 = curr % 3;
    int m2 = req % 3;

    if (m1 == m2)
    {
        return 0;
    }
    if (m1 < m2)
    {
        return m2 - m1;
    }
    return m2 + (3 - m1);
}

int solver(vector<int> &a)
{
    int ans = 0;
    for (int i = 3; i < a.size(); i++)
    {
        ans += change_mod(a[i], a[i - 3]);
        a[i] = a[i - 3];
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int res = solver(a);
        cout<<res<<endl;
    }

    return 0;
}