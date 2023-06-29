#include <stdio.h>
int main(){
    int age;
    printf("Enter your age here: ");
    scanf("%d", &age);
    if (age<18)
    {
        printf("you can NOT drive");
    }
    else
    {
        printf("You can drive");
    }
    return 0;
}