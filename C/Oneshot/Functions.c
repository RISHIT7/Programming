#include <stdio.h>

// data_type func_name(parameter_type parameter){
//     return value_of_datatype
// }

char newPrint(char *char1)
{
    printf("%s\n", char1);
}

int sum(int a, int b)
{
    return a + b;
}

float average(float a, float b)
{
    return (a + b) / 2;
}

int main()
{
    printf("*******Functions*******\n\n");
    newPrint("Hello world");
    printf("%d", sum(100, 299));
    printf("%f", average(100, 299));
    return 0;
}