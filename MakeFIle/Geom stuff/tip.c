#include <stdio.h>

int main()
{
    double tip, price;
    printf("Enter the price here: ");
    scanf("%lf", &price);

    printf("Enter the tip amount (percent) : ");
    scanf("%lf", &tip);

    double tip_amt, total_price;
    tip_amt = tip*price / 100;
    total_price = price + tip_amt;

    printf("The total price to be paid is %lf\n", total_price);
    printf("The tip to be paid is %lf\n", tip_amt);

    return 0;
}