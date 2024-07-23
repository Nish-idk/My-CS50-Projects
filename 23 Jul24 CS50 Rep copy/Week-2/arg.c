#include <stdio.h>
#include <cs50.h>

void wwhile(string array[]);
void ffor(string array[]);
int main(int argc, string argv[])
{
    printf("hello, ");
}

void wwhile(string array[])
{
    int i = 0;
    while(array[i] != NULL)
    {
         printf("%s ", array[i]);
         i++;
    }
    printf("\n");
}

void ffor(string array[])
{
    for(int i = 0; i < argc + 1; i++) // to print the null character too
    {
        printf("%s ", array[i]);
    }
    printf("\n");
}
