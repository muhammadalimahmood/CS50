#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Minutes: ");
    unsigned int n = get_int();

    printf("Bottles: %i\n", n * 12);
}