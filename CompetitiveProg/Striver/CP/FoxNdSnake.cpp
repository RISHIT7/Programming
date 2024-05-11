#include <iostream>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    bool first = true;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (j % 2 == 0)
            {
                cout << "#";
            }
            if (j % 2 == 1 && first)
            {
                if (i == m - 1)
                {
                    cout << "#";
                }
                else
                {
                    cout << ".";
                }
            }
            if (j % 2 == 1 && !first)
            {
                if (i == 0)
                {
                    cout << "#";
                }
                else
                {
                    cout << ".";
                }
            }
        }
        if (j % 2 == 1)
            first = !first;
        cout << endl;
    }
    return 0;
}