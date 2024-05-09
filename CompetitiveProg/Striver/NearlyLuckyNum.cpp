#include <iostream>
using namespace std;

int main()
{

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  unsigned long long int s;
  cin >> s;

  int temp_val;
  unsigned long long int count{};
  while (s > 0)
  {
    temp_val = s%10;
    if (temp_val == 4 || temp_val == 7)
      count++;
    s /= 10;
  }
  if (count == 0)
  {
    cout << "NO" << endl;
    return 0;
  }
  unsigned long long int n = count;
  
  int val;
  bool res = true;
  while (n > 0)
  {
    val = n%10;
    if (val != 4 && val != 7)
      res = false;
    n /= 10;
  }

  if (res)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  
  return 0;
}
