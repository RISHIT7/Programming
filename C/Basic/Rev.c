#include <stdio.h>

int main(){
    int j;
    printf("Enter the number of elements here: ");
    scanf("%d", &j);
    int arr[j];
    printf("Enter the elements here:\n");
    for (int i = 0; i < j; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < j; i++)
    {
        for (int i = 0; i < j-1; i++)
        {
            /* code */
        }
        
    }
    
    return 0;
}