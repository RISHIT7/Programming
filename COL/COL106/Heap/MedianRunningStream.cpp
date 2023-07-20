#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

priority_queue<int, vi, greater<int>> pqmin;
priority_queue<int, vi> pqmax;

void insert(int x)
{
    if (pqmin.size() == pqmax.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
            return;
        }
        if (x < pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {
        if (pqmax.size() > pqmin.size())
        {
            if (x >= pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x)
            }
        }
        else
        {
            if (x <= pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian()
{
    if (pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top()) / 2.0;
    }
    else if (pqmax.size() > pqmin.size())
    {
        return pqmax.top();
    }
    else
    {
        return pqmin.top();
    }
}

int main()
{
    insert(10);
    cout << findMeadian() << endl;
    return 0;
}