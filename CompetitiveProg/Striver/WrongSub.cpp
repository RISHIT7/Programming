#include <iostream>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  long long int n, m;
  cin >> n >> m;

  int val = 0;
  while (m--)
  {
    val = n%10;
    if (val != 0)
    {
      n -= 1;
    }
    else
    {
      n /= 10;
    }
  }

  cout << n << endl;
  return 0;
}
