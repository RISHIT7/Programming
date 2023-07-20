#include <bits/stdc++.h>
using namespace std;

bool redundant(string s)
{
    stack<char> st;
    bool ans = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
                return ans;
            }
            while (!st.empty() and st.top() != '(')
            {
                st.pop();
            }
            st.pop();
        }
    }
    return ans;
}

int main()
{
    string expression = "(a+(a+b))";
    cout << redundant(expression) << endl;
    return 0;
}