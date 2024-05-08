#include <iostream>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  cin >> t;

  long int res = 0;
  while (t--)
  {
    string s;
    cin >> s;

    if ("Icosahedron" == s)
    {
      res += 20;
    }
    else if ("Dodecahedron" == s)
    {
      res += 12;
    }
    else if ("Octahedron" == s)
    {
      res += 8;
    }
    else if ("Cube" == s)
    {
      res += 6;
    }
    else if ("Tetrahedron" == s)
    {
      res += 4;
    }
  }

  cout << res << endl;
  return 0;
}
