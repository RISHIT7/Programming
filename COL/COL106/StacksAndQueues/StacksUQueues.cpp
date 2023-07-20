#include <bits/stdc++.h>
#include <queue>
using namespace std;

class stack
{
private:
    queue<int> q;

public:
    void push(int val)
    {
        queue<int> temp;
        temp.push(val);
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            temp.push(k);
        }
        swap(q, temp);
    }
    void pop()
    {
        q.pop();
    }
    int peek()
    {
        return q.front();
    }
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    return 0;
}