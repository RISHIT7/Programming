#include <bits/stdc++.h>
using namespace std;

void right(vector<vector<int>> arr, int n, int i, int j)
{
  for (int k = 0; k < n; k++)
  {
    cout << arr[i][j+k] << " ";
  }
}

void down(vector<vector<int>> arr, int n, int i, int j)
{
  for (int k = 0; k < n; k++)
  {
    cout << arr[i+k][j] << " ";
  }
}

void left(vector<vector<int>> arr, int n, int i, int j)
{
  for (int k = 0; k < n; k++)
  {
    cout << arr[i][j-k] << " ";
  }  
}

void up(vector<vector<int>> arr, int n, int i, int j)
{
  for (int k = 0; k < n; k++)
  {
    cout << arr[i-k][j] << " ";
  }
}

int main()
{

  vector<vector<int>> Matrix1 = { { 1, 2, 3 },
	              { 4, 5, 6 },
		      { 7, 8, 9 } };

	vector<vector<int>> Matrix2 = { { 1, 2, 3, 4 },
		      { 5, 6, 7, 8 },
		      { 9, 10, 11, 12 },
	              { 13, 14, 15, 16 } };

  int n = 3;
  int i{1}, j{1};
  while (n > 1)
  {
    right(Matrix1, n-1, i-1, j-1);
    j += n-1;
    down(Matrix1, n-1, i-1, j-1);
    i += n-1;
    left(Matrix1, n-1, i-1, j-1);
    //i -= n;
    //up(Matrix1, n-1, i-1, j-1);
    n -= 1;
    //i = 0;
    //j = 0;
  }
  cout << "\n";

  
  return 0;
}
