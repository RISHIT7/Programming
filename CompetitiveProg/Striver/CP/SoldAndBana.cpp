#include <iostream>
using namespace std;

int main()
{

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  unsigned long long int k, n, w;
  cin >> k >> n >> w;

  unsigned long long int val = k*(w*(w+1))/2;
  if (val < n)
    cout << 0 << endl;
  else
    cout << val - n << endl;
  return 0;
}
