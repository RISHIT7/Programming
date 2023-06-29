#include <iostream>
#include <algorithm>
using namespace std;

string reverse(int i, int n, string s)
{
    if (n!=i)
    {
        swap(s[i], s[s.length()-i-1]);
        reverse(i+1, n, s);
    }
    return s;
}

int main()
{
    int n, i=0;
    string s;
    cin>>s;
    n = s.length()/2;
    cout<<reverse(i, n, s)<<endl;
    return 0;
}