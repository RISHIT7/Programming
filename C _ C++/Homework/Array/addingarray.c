#include <stdio.h>
int main()
{
    int j;
    printf("Enter size of array: ");
    scanf("%d", &j);
    int arr1[j];
    int arr2[j];
    int arr[j];
    printf("Enter %d elements of array A: \n", j);
    for (int i = 0; i < j; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter %d elements of array B: \n", j);
    for (int i = 0; i < j; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < j; i++)
    {
        arr[i] = arr1[i] + arr2[i];
    }
    printf("The third array is: \n");
    for (int i = 0; i < j; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}