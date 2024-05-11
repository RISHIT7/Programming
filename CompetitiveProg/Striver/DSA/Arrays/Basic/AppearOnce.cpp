#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n ;i++)
  {
    cin >>> arr;
  }

  int ans{arr[0]};

  for (int i = 1; i < n; i++)
  {
    ans = ans ^ arr[i];
  }

  cout << ans << endl;

  return 0;
}
