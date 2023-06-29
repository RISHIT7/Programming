#include <iostream>
using namespace std;

int main()
{
    int div, n;
    div = 2;
    printf("Enter the number here: ");
    scanf("%d", &n);
    while (div < n)
    {
        if (n%div == 0)
        {
            printf("Not a prime number");
            break;
        }
        else if (div == n-1)
        {
            printf("Is a prime number");
        }
        div += 1;
    }
    return 0;
}