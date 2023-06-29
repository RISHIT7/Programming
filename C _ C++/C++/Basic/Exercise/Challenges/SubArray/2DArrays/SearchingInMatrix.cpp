#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool flag = false;
    int target, a=0;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == target)
            {
                cout << "Row=" << i << " "
                     << "Column=" << j << endl;
                a += 1;
                flag = true;
            }
        }
    }
    if ((a==n*m)&&(flag==false))
    {
        cout<<-1<<endl;
    }
    return 0;
}