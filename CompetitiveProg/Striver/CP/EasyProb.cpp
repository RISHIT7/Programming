#include <iostream>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin>> n;

  int res = false;
  int temp;
  while (n--)
  {
    cin >> temp;
    if (temp == 1)
    {
      res = true;
    }
  }

  if (res)
  {
    cout << "HARD" << endl;
  }
  else
    cout << "EASY" << endl;
  return 0;
}
