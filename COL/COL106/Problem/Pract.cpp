#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void print_arr(vector<ll> arr)
{
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void mex(vector<ll> arr, vector<ll> ans)
{
    if (arr[0] == 0)
    {
        ll s = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            s += arr[i];
        }
        for (int i = 0; i < s; i++)
        {
            ans.push_back(0);
        }
    }
    else
    {
        int index = 0;
        while (arr[index] != 0)
        {
            arr[index] -= 1;
            index++;
        }
        ans.push_back(index + 2);
        mex(arr, ans);
    }
    print_arr(ans);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr;
        for (ll i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            arr.push_back(k);
        }
        vector<ll> count;
        ll max = arr[0];
        for (ll i = 0; i < n; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        for (ll i = 0; i <= max; i++)
        {
            count.push_back(0);
        }
        for (ll i = 0; i < n; i++)
        {
            count[arr[i]] += 1;
        }
        mex(count, {});
        return 0;
    }
}