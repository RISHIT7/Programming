#include <stdio.h>
int main()
{
    int j = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the number for index %d here: ", i);
        scanf("%d", &arr[i]);
        j = j + arr[i];
    };
    printf("Sum = %d", j);
    return 0;
}