#include <iostream>
using namespace std;

void checkPalindrome()
{
    int n;
    cin >> n;
    char arr[n];
    cin >> arr;
    int i = 0;
    bool check = true;
    while (i != '\0')
    {
        if (arr[i] == arr[n - i - 1])
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }
}

int main()
{
    checkPalindrome();

    return 0;
}