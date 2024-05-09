#include <iostream>
using namespace std;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  string s;
  cin >>s;

  int size = s.size();
  int count[3] = {0,0,0};

  int i = 0;
  while (i < size)
  {
    if (s[i] == '1')
    {
      count[0]++;
    }
    else if (s[i] == '2')
    {
      count[1]++;
    }
    else
    {
      count[2]++;
    }
    
    
    i += 2;
  }
  
  i = 0;
  while (i < size)
  {
    if (i % 2 == 1)
    {
      cout << "+";
      i++;
      continue;
    }

    if (count[0] > 0)
    {
      cout << "1";
      count[0]--;
    }
    else if (count[1] > 0)
    {
      cout << "2";
      count[1]--;
    }
    else if (count[2] > 0)
    {
      cout << "3";
      count[2]--;
    }

    i++;
  }
  cout << endl;
  
  return 0;
}
