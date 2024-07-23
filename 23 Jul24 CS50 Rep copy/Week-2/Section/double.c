#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int sequence[32];
    sequence[0]= 1;

    for (int i = 0; i < 32; i++)
    {
        sequence[i + 1] = sequence[i] * 2;
        printf("%i\n", sequence[i]);
    }
}
