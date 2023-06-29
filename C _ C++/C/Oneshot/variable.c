#include <stdio.h>

int main()
{
    unsigned int integer = 8;
    char c1 = 'c'; // 1 bit

    short int d = 2;  // 2 bytes
    int a1 = 7;       // 2 to 4 bytes
    long int e = 181; // 4 bytes
    float b1 = 8.0;   // 4 bytes - 6 decimal places

    double float1 = 44.45;              // 8 bytes - 15 decimal places
    long double float2 = 44.2094573487; // 10 bytes - 19 decimal places

    printf("The size taken by int is %d bytes\n", sizeof(int)); // similarly for other types of variables

    printf("\n*********Rules for creating variables*********");
    char rishitAge; // varibale declaration
    rishitAge = 18; // variable initialization

    const int i = 9; // i is now a read only variable

    printf("\n\n*********Type of Operators*********\n\n");
    /*
    Arithmetic Operators
    Realtion Operators
    Logical Operators
    Bitwise Operators
    Assignment Operators
    Misc Operators
    */
    int a = 6, b = 7, c = 8;
    int d = 1, e = 0;
    printf("sum of a and b is %d\n", a + b);
    printf("%d\n", a != b);
    printf("the logical operator returned %d\n", d && e);
    printf("the logical operator returned %d\n", d || e);
    printf("the logical operator returned %d\n"), !d;
    printf("the logical operator returned %d\n"), !e;
    // Bitwise Operators
    // A = 60, B = 13
    int A = 60, B = 13;
    printf("bitwise operator returned %d\n", A & B);  // and operator
    printf("bitwise operator returned %d\n", A | B);  // or operator
    printf("bitwise operator returned %d\n", A ^ B);  // xor operator
    printf("bitwise operator returned %d\n", ~B);     // complement operator
    printf("bitwise operator returned %d\n", A << B); // left shift operator
    printf("bitwise operator returned %d\n", A >> B); // right shift operator
    /* Assignmnet operators
    =, +=, -=, *=, %=, etc */
    /* Misc Operators 
    -, &, *, ?: */
    return 0;
}
