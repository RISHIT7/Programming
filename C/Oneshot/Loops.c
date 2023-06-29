#include <stdio.h>
int main(){
    printf("*******Loops*******\n\n");
    int index = 0;
    while (index < 10)
    {
        printf("%d\n", index);
        index += 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    int i = 0;
    do
    {
        printf("do while loop is running");
    } while (i > 5);
    return 0;
}