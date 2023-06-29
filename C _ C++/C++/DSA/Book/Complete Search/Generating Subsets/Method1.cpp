#include <iostream>
#include <vector>
using namespace std;

void search(int k, int n, vector<int> subset)
{
    if (k == n)
    {
        for (int i = 0; i < subset.size(); i++)
        {
            cout<<subset[i]<<" ";
        }
        cout<<endl;        
    }
    else
    {
        search(k+1, n, subset);
        subset.push_back(k);
        search(k+1, n, subset);
        subset.pop_back();
    }
}

int main()
{
    int R = 1;
    vector<int> subset = {};
    int N = 4;
    cout << "Subsets for set 1:" << endl;
    search(R, N, subset);
    return 0;
}