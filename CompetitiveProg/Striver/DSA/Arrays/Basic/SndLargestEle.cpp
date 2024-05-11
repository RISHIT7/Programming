#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {1, 2, 4, 5, 4, 3, 1};
  int max[] = {-1 , -1};
  for (auto a: arr)
  {
    if (a > max[1])
    {
      max[0] = max[1];
      max[1] = a;
    }
  }
  cout << max[0] << endl;
  
  return 0;
}
