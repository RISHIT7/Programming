#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20

int main()
{
    int size;
    int arr[MAXSIZE];
    int i;

    while (scanf("%d", &size) != -1)
    {
        for (i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
        int ind = 0;
        for (i = 0; i < size; i++)
        {
            bool isPrime = true;
            for (int j = 2; j < arr[i]; j++)
            {
                if (arr[i] % j == 0)
                {
                    isPrime = false;
                }
            }
            if (arr[i] == 1)
            {
                isPrime = false;
            }
            if (isPrime == true)
            {
                int temp = arr[i];
                arr[i] = arr[ind];
                arr[ind] = temp;
                ind++;
            }
        }
        i = ind;
        while (i < size)
        {
            int j = ind;
            while (j < size - 1)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
                j++;
            }
            i++;
        }
        for (i = 0; i < ind; i++)
        {
            for (int j = 0; j < ind-i-1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        for (i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
