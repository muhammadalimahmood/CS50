#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();

    for(int i = 0, n = strlen(name); i < n; i++ )
    {
        if(name[i] == ' ')
        {
            while (name[i] == ' ')
            {
                i++;
            }
            if (name[i] != '\0')
            {
                printf("%c", toupper(name[i]));
            }
        }
        else if (name[i] != ' ' && i == 0)
        {
            printf("%c", toupper(name[i]));
        }
    }
    printf("\n");
}