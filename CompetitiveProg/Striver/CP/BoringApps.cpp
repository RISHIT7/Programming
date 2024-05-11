#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int t;
  cin >> t;
  
  while (t--)
  {
    string n;
    cin >> n;

    int dig = stoi(n.substr(0, 1));
    int size = n.size();

    int ans = (10*(dig-1)) + (size*(size+1))/2;
    cout << ans << endl;
  }
  
  return 0;
}
