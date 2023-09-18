#include <stdio.h>

int main()
{
    int x, y, z;
    char xc, yc, zc;

    x = 0xF0;xc = x; // x = 11110000
    printf("x is: %d\n", x);
    y = 0x8D; yc = y; // y = 10001101
    printf("y is: %d\n", y);
    printf("xc is: %d\n", xc);
    z = x & y;
    printf("x & y is: %d\n", z);
    z = x | y;
    printf("x | y is: %d\n", z);
    z = (x >> 2); // 0011 1100, 3c
    printf("x >> 2 is: %x\n", z); // %x is hex, %o is octal
    z = (xc >> 2);
    printf("xc >> 2 is: %x\n", z); // %x is hex, %o is octal
    
    return 0;
}