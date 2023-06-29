#include <iostream>
using namespace std;

void replace(string s)
{
    if (s.length() == 0)
    {
        return ;
    }
    if (s[0]=='p' && s[1]=='i')
    {
        cout<<"3.14";
        replace(s.substr(2));
    }
    else
    {
        cout<<s[0];
        replace(s.substr(1));
    }
}

int main()
{
    string s;
    cin >> s;
    replace(s);
    return 0;
}