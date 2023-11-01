#include <stdio.h>

double get_double(char* prompt, double min, double max);

int main()
{
    double tip, price;
    price = get_double("Enter the price here: ", 0, 1000);

    tip = get_double("Enter the tip amount (percent) : ", 0, 100);

    double tip_amt, total_price;
    tip_amt = tip*price / 100;
    total_price = price + tip_amt;

    printf("The total price to be paid is %lf\n", total_price);
    printf("The tip to be paid is %lf\n", tip_amt);

    return 0;
}