#include <stdio.h>
#include <math.h>

#include "gd.c"

int main(int argv, char *argc[])
{
    double x = get_double("Enter the x value: ", -100, 100);
    double y = get_double("Enter the y value: ", -100, 100);

    double d = sqrt(pow(x, 2) + pow(y, 2));

    printf("Distance is %lf meters\n", d);
    return 0;
}