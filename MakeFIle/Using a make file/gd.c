#include <stdio.h>

double get_double(char *prompt, double min, double max)
{
    double input;

    do
    {
        printf("%s", prompt);
        scanf("%lf", &input);
        if (input < min) printf("The input must atleast be %lf\n", min);
        if (input > max) printf("The input must atmost be %lf\n", max);
    } while (input < min || input > max);

    return input;
}