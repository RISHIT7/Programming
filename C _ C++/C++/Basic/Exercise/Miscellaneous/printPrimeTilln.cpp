#include <iostream>
using namespace std;

int main()
{
    int n;
    printf("Enter the number here: ");
    scanf("%d", &n);
    printf("In 1 to %d\n\n", n);
    printf("2 is a prime\n");
    for (int i = 0; i < n; i++)
    {
        for (int div = 2; div < n; div++)
        {
            if (i % div == 0)
            {
                break;
            }
            else if (div == i - 1)
            {
                printf("%d is a prime number\n", i);
            }
        }
    }
    return 0;
}