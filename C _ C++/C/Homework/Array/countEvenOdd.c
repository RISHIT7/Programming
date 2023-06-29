#include <stdio.h>
int main()
{
    int e, j, arr[j];
    printf("Enter The number of elements: \n");
    scanf("%d", &j);
    printf("Enter %d elements\n", j);
    for (int i = 0; i < j; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
        {
            e += 1;
        }
    }
    printf("Number of even numbers are: %d", e);
    printf("Number of odd numbers are: %d", j - e);
    return 0; 
}