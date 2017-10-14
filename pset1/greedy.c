#include <stdio.h>
#include <cs50.h>
#include <math.h>

int coins(float change);

int main(void)
{
    float change;

    printf("O hai!");

    do
    {
        printf("How much change is owed?\n");
        change = get_float();
    }while(change < 0);

    int cents = coins(change);

    printf("%i\n", cents);
}

int coins(float change)
{
    int cents = round(change * 100);

    int n = cents / 25;
    cents = cents % 25;

    n = n + (cents / 10);
    cents = cents % 10;

    n = n + cents / 5;
    cents = cents % 5;

    n = n + cents;

    return n;
}