#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int a;
  cin >> a;

  int ans{};
  while (a >= 0)
  {
    a -= (ans*(ans+1)/2);
    if (a >= 0)
    {
      ans++;
    }
  }

  cout << ans-1 << endl;
  return 0;
}
