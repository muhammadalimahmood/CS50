#include <stdio.h>
#include <cs50.h>

void card(long number);

int main(void)
{
    long number;
    do
    {
        printf("Number: ");
        number = get_long();
        printf("%ld\n", number);
    }while(number <= 0);
    card(number);
}

void card(long number)
{

}