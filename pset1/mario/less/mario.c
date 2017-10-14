#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();

    }while (height > 23 || height < 0);

    int counter = height - 1;

    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= height; j++)
        {
            if (j >= counter)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        counter--;
    }
}