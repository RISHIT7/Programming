#include <iostream>
using namespace std;

int coutnPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += coutnPath(s + i, e);
    }
    return count;
}

int main()
{
    cout << coutnPath(0, 3) << endl;
    return 0;
}