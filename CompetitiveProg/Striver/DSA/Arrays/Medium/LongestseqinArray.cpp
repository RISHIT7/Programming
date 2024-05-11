#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr(n);
  int temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    arr[i] = temp;
  }

  sort(arr.begin(), arr.end());
  int val{};
  int ans{};
  for (int i = 0; i < n-1; i++)
  {
    val = arr[i];
    if (arr[i+1] == val+1)
    {
      ans += 1;
    }
  }
  cout << ans << endl;   
  return 0;
}
