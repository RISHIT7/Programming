#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str = "askjghlsufygg";

    cout << 'a' - 'A' << endl; // 32
    // to upper

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    cout << str << endl;
    // to lower

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    cout << str << endl;

    // inbuilt function for the "babal"

    string s = "AddgfAEDFDDargsdfdg";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
    return 0;
}