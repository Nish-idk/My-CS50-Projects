#include <ctype.h>
#include <cs50.h>
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

    // Converting plaintext ASCII to alphabetical index ie; assuming A = 0, B = 1... Z = 26
    for (int i = 0, length = strlen(p); i < length; i++)
    {
        if (isupper(p[i]))
        {
            p[i] = p[i] - 'A';
        }
        if (islower(p[i]))
        {
            p[i] = p[i] - 'a';
        }
    }

    printf("%sis nice\n", p);
    printf("%s%s%s%s%s%s%s", p, p, p, p, p, p, p);
}
// Code does work until this point
