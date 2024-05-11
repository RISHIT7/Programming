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

  cout << "----------------------\n";
  print(mat);

  // transpose
  vector<vector<int>> trans_mat(m , vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      trans_mat[j][i] = mat[i][j];
    }
  }

  cout << "------------------------\n";
  print(trans_mat);

  // swapping
  for (int i = 0; i < n/2; i++)
  {
    for (int j = 0; j < m; j++)
    {
      temp = trans_mat[j][i];
      trans_mat[j][i] = trans_mat[j][n-i-1];
      trans_mat[j][n-i-1] = temp;
    }
  }

  cout << "----------------------------\n";
  print(trans_mat);
  
  return 0;
}
