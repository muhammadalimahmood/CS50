#include <stdlib.h> // preprocessor directive to include llibrary that has atoi()
#include <stdio.h>
#include <cs50.h>
#include <string.h> // to include strlen()
#include <ctype.h> // to include isupper()

char encrypt(char c, char k);
int alphabetical_index(char c);

int main(int argc, string argv[])
{
    // check whether the input is correct
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    int len = strlen(argv[1]);

    for(int i = 0; i < len; i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    //getting text to be encrypted
    printf("plaintext: ");
    string text = get_string();
    //enciphering
    for(int i = 0, j = 0, len1 = strlen(text); i < len1 ; i++)
    {
        if (isalpha(text[i]))
        {
            text[i] = encrypt(text[i], argv[1][j]);
            j++;
        }
        j = j % len; //to make sure j doesn't exceed the length of key word
    }
    printf("ciphertext: %s\n", text);
}

//function to encrypt one letter
char encrypt(char c, char k)
{
    c = alphabetical_index(c);
    k = alphabetical_index(k);
    return (isupper(c))?(c + k) % 26 + 'A' :(c + k) % 26 + 'a';
}

//determine the alphabetical character
int alphabetical_index(char c)
{
    return isupper(c) ? c % 'A': c % 'a';
}