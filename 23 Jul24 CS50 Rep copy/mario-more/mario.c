// Prints a double-pyramid

#include <cs50.h>
#include <stdio.h>

void print_pyramid(int x);
void print_level(int level);
int main(void)
{
    int height;
    // Prompts user for height
    do
    {
        height = get_int("input height between 1 and 8: ");
    }
    while (height < 1 || height > 8);
    print_pyramid(height);
}

void print_pyramid(int x)
{
    // Make 'height' number of levels
    for (int j = 0; j < x; j++)
    {
        // Align levels to the right
        for (int k = 0; k < x - j - 1; k++)
        {
            printf(" ");
        }

        // Make appropriate length of levels
        print_level(j);

        // Mirror image
        printf("  ");
        print_level(j);

        printf("\n");
    }
}

void print_level(int level)
{
    for (int i = 0; i < level + 1; i++)
    {
        printf("#");
    }
}
