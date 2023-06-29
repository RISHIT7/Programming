#include <stdio.h>

int main(){
    printf("*******Taking input from user in C*******");
    int input;
    printf("\nPlease enter an input: ");
    scanf("%d", &input);
    printf("\nYou entered %f as input\n", (float) input);

    int num1, num2;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    printf("The division of the above two numbers is: %f", (float) num1/num2);
    return 0;
}