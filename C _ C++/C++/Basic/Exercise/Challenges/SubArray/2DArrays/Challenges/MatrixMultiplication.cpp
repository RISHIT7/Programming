#include <iostream>
using namespace std;

int main()
{
    int n1, m1;
    cin >> n1 >> m1;
    int a1[n1][m1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> a1[i][j];
        }
    }
    int n2, m2;
    cin >> n2 >> m2;
    int a2[n2][m2];
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> a2[i][j];
        }
    }
    int ans[n1][m2];
    if (m1 != n2)
    {
        cout << "Enter valid matrices" << endl;
    }
    else
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                for (int k = 0; k < m2; k++)
                {
                    ans[i][j] += a1[i][k] * a2[k][j];
                }
            }
        }
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}