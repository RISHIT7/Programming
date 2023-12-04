#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n = 5;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    map<int, int> parents;
    for (auto i : edges)
    {
        int a = i.first;
        int b = i.second;

        if (a > b)
        {
            int temp = a;
            a = b;
            b = a;
        }

        if (parents.count(a) == 0)
        {
            parents[b] = a;
        }
        else if (parents.count(a) != 0)
        {
            parents[b] = parents[a];
        }
    }

    set<int> count;
    for (map<int, int>::iterator i = parents.begin(); i != parents.end(); i++)
    {
        count.insert(i->second);
    }
    cout << count.size() << endl;
    

    return 0;
}