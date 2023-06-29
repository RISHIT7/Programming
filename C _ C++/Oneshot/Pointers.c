#include <stdio.h>
int main()
{
    int a = 98;
    printf("%d", a);
    int *ptr = NULL;
    if (!ptr)
    {
        printf("pointee  is not null");
    }
    ptr = &a; // pointers store the address of the other variables but can also
              // change the value of the previous variable
    *ptr = 988;
    printf("%d", a);
    return 0;
}