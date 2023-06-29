#include <stdio.h>

int main()
{
    int num, sum=0;
    printf("Enter a five digit number: ");
    scanf("%d", &num);
    for (int i = 0; i < 5; i++)
    {
        sum += num%10;
        num = num/10;
    }
    printf("The sum of the digits of the number is %d\n", sum);
    return 0;
}