#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> mat)
{
  for (int i = 0; i < mat.size(); i++)
  {
    for (int j = 0; j < mat[0].size(); j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat;
  vector<int> temp_vec;
  int temp;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> temp;
      temp_vec.push_back(temp);
    }
    mat.push_back(temp_vec);
    temp_vec.clear();
  }

  // markers
  int col = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == 0)
      {
        // rows
        mat[i][0] = 0;

        // columns
        if (j == 0)
        {
          col = 0;
        }
        else
        {
          mat[0][j] = 0;
        }
      }
    }
  }

  // modification for the smaller matrix
  for (int i = n-1; i > 0; i--)
  {
    for (int j = m-1; j > 0; j--)
    {
      if (mat[i][0] == 0 || mat[0][j] == 0)
      {
        mat[i][j] = 0;
      }
    }
  }

  // dealing with the rest of row
  if (mat[0][0] == 0)
  {
    for (int i = 0; i < m; i++)
    {
      mat[0][i] = 0;
    }
  }

  // dealing with the rest of column
  if (col == 0)
  {
    for (int i = 0; i < n; i++)
    {
      mat[i][0] = 0;
    }
  }

  print(mat);  
  return 0;
}
