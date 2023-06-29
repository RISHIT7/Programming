#include <iostream>
using namespace std;

// once we want to add the char, and once we dont, so 2 cases for each letter, giving 2^n

void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);

    subseq(ros, ans);
    subseq(ros, ans+ch);
}

int main()
{
    subseq("ABC", "");
    return 0;
}