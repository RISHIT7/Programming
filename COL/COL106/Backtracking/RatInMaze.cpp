#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x<n && y<n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool RatInMaze(int **arr, int x, int y, int n, int **solArr)
{
    if ((x==n-1) && (y==(n-1))){
        solArr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n)){
        solArr[x][y] = 1;
        if (RatInMaze(arr, x+1, y, n, solArr) || RatInMaze(arr, x, y+1, n, solArr))
        {
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    return 0;
}