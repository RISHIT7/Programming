#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  long int n;
  cin >> n;

  vector<long long int> arr(n);
  for (long int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  long int ans{};
  long int count{1};
  for (long int i = 0; i < n-1; i++)
  {
    if (arr[i] < arr[i+1])
    {
      count++;
    }
    else
    {
      if (count > ans)
      {
        ans = count;
      }
      count = 1;
    }
  }
  if (count > ans)
  {
    ans = count;
  }
  cout << ans << endl;

  return 0;
}
