#include <stdlib.h> // preprocessor directive to include llibrary that has atoi()
#include <stdio.h>
#include <cs50.h>
#include <string.h> // to include strlen()
#include <ctype.h> // to include isupper()

char encrypt(char text, int k);

int main(int argc, string argv[])
{
    // check whether the input is correct
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    //converts string to int
    int k = atoi(argv[1]);

    //getting text to be encrypted
    printf("plaintext: ");
    string text = get_string();
    //enciphering
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        text[i] = encrypt(text[i], k);
    }
    printf("ciphertext: %s\n", text);
}

//function to encrypt one letter
char encrypt(char text, int k)
{
    if(isalpha(text))
    {
        return (isupper(text))?(text % 'A' + k) % 26 + 'A' :(text % 'a' + k) % 26 + 'a';
    }

    else
        return text;
}