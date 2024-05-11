#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  string s;
  cin >> s;

  string temp;
  bool ans = false;
  for (int i = 0; i < 5; i++)
  {
    cin >> temp;
    if (temp.substr(0, 1) == s.substr(0, 1))
    {
      ans = true;
      break;
    }
    if (temp.substr(1, 1) == s.substr(1, 1))
    {
      ans = true;
      break;
    }
  }

  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
