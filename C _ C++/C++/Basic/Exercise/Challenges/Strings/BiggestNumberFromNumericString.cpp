#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s = "9465739";
    sort(s.begin(), s.end());
    string ulta_s(s.length(), 'n');
    for (int i = 0; i < s.length(); i++)
    {
        ulta_s[i] = s[s.length() - i - 1];
    }
    cout << ulta_s << endl;
    // OR
    string a = "6346545168";
    sort(a.begin(), a.end(), greater<int>());
    cout << a << endl;
    return 0;
}