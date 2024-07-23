#include <stdio.h>

int main(void)
{
    int array[100];

    for(int i = 0; i < 100; i++)
    {
        array[i] = i;
    }

    for(int j = 46; j < 78; j++)
    {
        printf("array[%i] = %i\n", j, j);
    }
}
