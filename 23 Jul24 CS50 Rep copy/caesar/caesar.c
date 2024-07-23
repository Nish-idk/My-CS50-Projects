// Converts plaintext to ciphertext

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Ensuring argc = 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Ensuring command line argument passed is a non-negative digit
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isalpha(argv[1][i]) || isspace(argv[1][i]) || ispunct(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converting key to integer
    int key = atoi(argv[1]);
    int k = key;

    // Getting plaintext input
    string plaintext = get_string("plaintext:  ");
    string p = plaintext;
    const int LENGTH = strlen(p);

    // Defining integer array for alphabetical index
    int index[LENGTH];

    /* Converting plaintext ASCII to alphabetical index ie; assuming A = 0, B = 1... Z = 26 whilst
       conserving plaintext */
       
    for (int i = 0; i < LENGTH; i++)
    {
        if (isupper(p[i]))
        {
            index[i] = p[i] - 'A';
        }
        else if (islower(p[i]))
        {
            index[i] = p[i] - 'a';
        }
    }

    // Converting to ciphertext
    char c[LENGTH + 1];

    for (int i = 0; i < LENGTH; i++)
    {
        if (isupper(p[i]))
        {
            c[i] = (index[i] + k) % 26 + 'A';
        }
        if (islower(p[i]))
        {
            c[i] = (index[i] + k) % 26 + 'a';
        }
        if (ispunct(p[i]) || isspace(p[i]))
        {
            c[i] = p[i];
        }
    }

    // Printing ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%c", c[i]);
    }
    printf("\n");
}
