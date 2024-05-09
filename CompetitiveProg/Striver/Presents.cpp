#include <iostream>
#include <vector>
using namespace std;

int main()
{

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> res(n, 0);
  int temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    res[temp-1] = i+1;
  }

  for (auto i: res)
  {
    cout << i << " ";
  }
  cout << endl;
  
  return 0;
}
