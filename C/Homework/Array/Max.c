#include <stdio.h>

int main()
{
    int max;
    int i;
    printf("How many elemnts do you want to add? ");
    scanf("%d", &i);
    int arr[i];
    printf("Enter %d values here: \n", i);
    for (int j = 0; j < i; j++)
    {
        scanf("%d", &arr[j]);
        if (arr[j] > max)
        {
            max = arr[j];
        };
    };
    printf("max = %d", max);
}