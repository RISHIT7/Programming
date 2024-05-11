#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  if (a%b == 0)
  {
    return b;
  }

  gcd(a, a%b);
}

int lcm(int a, int b)
{
  int gcd_val = gcd(a, b);
  return a*b/gcd_val;
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int a, b;
  cin >> a>> b;

  if (b > a)
  {
    int temp = b;
    b = a;
    a = temp;
  }
  
  cout << gcd(a, b) << " " << lcm(a, b) << endl;
  
  return 0;
}
