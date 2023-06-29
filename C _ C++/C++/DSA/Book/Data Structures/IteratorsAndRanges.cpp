#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {3, 4, 6, 8, 12, 13, 14, 17};
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    random_shuffle(v.begin(), v.end());
    set<int> s = {3, 2, 1, 4, 7, 8, 10};
    set<int>::iterator it = s.begin(); // creaates an iterator that points to the samllest element of the set
    // smaller way of writing this is
    auto it = s.begin();
    cout << *it << endl;
    // iterators can be moved forward using ++ and -- or += and -=
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }

    auto it = s.end();
    it--;
    cout << *it << endl; // prints the largest element

    auto it = s.find(1);
    if (it == s.end())
    {
        // x is not found
    }
    auto it = s.lower_bound(1); // returns an iterator to the smallest element with atleast value greater than x
    if (it == s.begin())
    {
        cout << *it << endl;
    }
    else if (it == s.end())
    {
        it--;
        cout << *it << endl;
    }
    else
    {
        int a = *it;
        it--;
        int b = *it;
        if (1 - b < a - 1)
            cout << b << endl;
        else
            cout << a << endl;
    }

    return 0;
}