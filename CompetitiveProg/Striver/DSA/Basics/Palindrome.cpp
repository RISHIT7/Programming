#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
  if (s.size() == 0 || s.size() == 1)
  {
    return true;
  }

  if (s.substr(0 ,1) != s.substr(s.size()-1, 1))
  {
    return false;
  }
  
  return palindrome(s.substr(1, s.size()-2));
}


int main()
{
  string s = "A man, a plan, a cnal: Panama";
  

  string tbc = "";
  for (int i = 0; i < s.length(); i++)
  {
    char c = (char)s[i];
    if ((c > 'z' || c < 'a') && (c > 'Z' || c < 'A'))
    {
      continue;
    }
    if (c <= 'Z' && c >= 'A')
    {
      c += 'a'-'A';
    }

    tbc.push_back(c); 
  }

  cout << palindrome(tbc) << endl;

  return 0;
}
