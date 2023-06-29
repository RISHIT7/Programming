#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m], target;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> target;
    int i = n - 1, j = 0;
    bool found = false;
    while (i < n and j >= 0)
    {
        if (a[i][j] > target)
        {
            j--;
        }
        if (a[i][j] < target)
        {
            i++;
        }
        else
        {
            found = true;
        }
    }
    cout << found << endl;
    return 0;
}
