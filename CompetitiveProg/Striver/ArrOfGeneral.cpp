#include <iostream>
#include <vector>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin>>n;

  vector<int> heights;

  int temp;
  for (int i =0; i<n;i++){
     cin >> temp;
     heights.push_back(temp);
  }


  int min{101}, max{-1}, minN{}, maxN{};
  for (int i = 0; i < n; i++)
  {
    if (min >= heights[i])
    {
      min = heights[i];
      minN = i;
    }

    if (max < heights[i])
    {
      max = heights[i];
      maxN = i;
    }
  }

  if (minN > maxN){
  cout << maxN + heights.size() - 1 - minN << endl;
  }
  else
  {
    cout << maxN + heights.size() - 2 - minN << endl;
  }
  return 0;
}
