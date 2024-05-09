#include <iostream>
using namespace std;

int main()
{

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;

  int m, q;
  int passangers{};
  int res{};
  while (n--)
  {
    cin >> m >> q;

    passangers += q - m;
    if (passangers > res)
      res = passangers;
  }

  cout << res << endl;
  
  return 0;
}
