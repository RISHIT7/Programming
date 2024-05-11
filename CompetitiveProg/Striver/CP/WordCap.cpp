#include <iostream>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  string s;
  cin >> s;

  int diff = 'A' - 'a';

  string rest = s.substr(1, s.size()-1);
  char first = s.at(0);

  if (first >= 'a' && first <= 'z')
  {
    first += diff;
  }
  
  cout << first <<  rest << endl;
 
  return 0;
}
