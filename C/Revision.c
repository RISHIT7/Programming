#include <stdio.h>

int main()
{
    int i, n;
    char s[] = "0123456789";
    n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9' ; i++)
    {
        n = 10*n+s[i] -'0';
    }
    int c = 123;
    if (c >= 'A' && c <= 'Z')
    {
        s = c + 'a' - 'A';
    }
    
    return 0;
}