#include <bits/stdc++.h>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int a, b;
  cin >> a >> b;

  double check = (double)b/a;
  double val = (double)3/2;

  int count = 0;
  while (val <= check)
  {
    val *= (double)3/2; 
    count++;
  }
  cout << ++count << endl;
 
  return 0;
}
