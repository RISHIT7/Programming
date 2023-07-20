#include <bits/stdc++.h>
#include <stack>
using namespace std;

class queue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val)
    {
        s1.push(val);
    }
    int pop()
    {
        while (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topvalue = s2.top();
        s2.pop();
        return topvalue;
    }
    bool isempty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}