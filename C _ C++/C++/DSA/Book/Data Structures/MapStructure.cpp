#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpischord"] = 9;
    cout << m["monkey"] << endl;    // 4
    cout << m["assfsffsd"] << endl; // 0
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}