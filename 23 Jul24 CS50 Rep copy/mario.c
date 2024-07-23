#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for positive integer
    int n = get_int("Size :");
    do
    {
        n = get ;
    }
    while (n < 1);

    // Print an n-by-n grid of bricks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
