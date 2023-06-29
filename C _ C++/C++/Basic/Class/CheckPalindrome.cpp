#include <iostream>
using namespace std;

void checkPalindrome()
{
    int n;
    cin >> n;
    char arr[n];
    cin >> arr;
    bool check;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[n - i - 1])
        {
            check = true;
        }
        else
        {
            check = false;
            break;
        }
    }

    if (check == true)
    {
        cout << "The word is a palindrome" << endl;
    }
    else
    {
        cout << "Not a palindrome" << endl;
    }
}

int main()
{
    checkPalindrome();
    return 0;
}