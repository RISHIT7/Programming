#include <iostream>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    long long int a, b, n;
    cin >> a >> b >> n;
    int c{};
    while (n >= a && n >= b)
    {
      if (a > b)
      {
        b += a;
      }
      else
      {
        a += b;
      }
      c += 1;
    }

    cout << c << endl;
  }
  return 0;
}
