#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int c;
    cin >> c;
    int n{};
    while (c--)
    {

        string s;
        cin >> s;

        if (s == "++X" || s == "X++")
        {
            n += 1;
        }
        else if (s == "--X" || s == "X--")
        {
            n -= 1;
        }
    }
    return 0;
}