#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    for (int i = n; i < m; i++)
    {
        for (int div = 2; div < i; div++)
        {
            if (i%div == 0)
            {
                break;
            }
            else if (div == i-1)
            {
                cout<< i <<endl;
            }
        }
    }
    return 0;
}