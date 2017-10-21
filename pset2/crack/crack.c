#define _XOPEN_SOURCE // always add at top of the file if want to use crypt()
#include <unistd.h>   // include crypt()

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> //

int crack_password(string key, string salt, string hash);

char *password;

int main(int argc, string argv[])
{
    // check the correctness of the cammand line execution of the function
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    int count = 1; // to count the number of characters in the key
    char salt[3] , key[5]; //salt is 2 char, one byte is for '\0'. Key is of 5 char
    salt[2] = '\0';

    bool result;    //to check whether password got cracke or not by the function crack_password

    for (int i = 0; i < 2; i++) //extracting salt from given hash
    {
        salt[i] = argv[1][i];
    }
    // generating all the possible keys and using brute force to find the password
    for (char c0 = 'A'; c0 <= 'z'; c0++)
    {
        if (!isalpha(c0)) //discarding all the symbols
        {
            continue;
        }
        for (char c1 = 'A'; c1 <= 'z'; c1++)
        {
            if (!isalpha(c1))
            {
                continue;
            }
            for (char c2 = 'A'; c2 <= 'z'; c2++)
            {
                if (!isalpha(c2))
                {
                    continue;
                }
                for (char c3 = 'A'; c3 <= 'z'; c3++)
                {
                    if (!isalpha(c3))
                    {
                        continue;
                    }
                    if (count == 1) // generating key of 1 character
                    {
                        key[0] = c3;
                        key[1] = '\0';
                    }
                    if (count == 2) // generating key of 2 characters
                    {
                        key[0] = c2;
                        key[1] = c3;
                        key[2] = '\0';
                    }
                    if (count == 3) // generating key of 3 characters
                    {
                        key[0] = c1;
                        key[1] = c2;
                        key[2] = c3;
                        key[3] = '\0';
                    }
                    if (count == 4) //// generating key of 4 characters
                    {
                        key[0] = c0;
                        key[1] = c1;
                        key[2] = c2;
                        key[3] = c3;
                        key[4] = '\0';
                    }
                    // passing the key and salt to generate hash and compare it to given hash
                    result = crack_password(key, salt, argv[1]);
                    if (!result)
                    {
                        return 0;
                    }

                    if (count == 1 && c3 == 'z') // reinitializing the variable after completing all
                    {                           //  all the possible combinitions for 1 character
                        count++;
                        c3 = 'A' - 1;
                    }
                }
                if (count == 2 && c2 == 'z')
                {
                    count++;
                    c2 = 'A' - 1;
                }
            }
            if (count == 3 && c1 == 'z')
            {
                count++;
                c1 = 'A' - 1;
            }
        }
    }
    return 1;
}
// function to find the hash value given key and salt. After that compare with the hash
int crack_password(string key, string salt, string hash)
{
    password = crypt(key , salt);

    //compare with hash
    if (strcmp(password, hash) == 0)
    {
        printf("%s\n", key);
        return 0;
    }

    return 1;
}