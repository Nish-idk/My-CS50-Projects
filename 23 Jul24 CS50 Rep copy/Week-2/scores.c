#include <stdio.h>
#include <cs50.h>

#define SIZE 3
int main(void)
{
    int scores[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        scores[i] = get_int("Score %i: ", i);
    }

    int sum = 0;
    for(int j = 0; j < SIZE; j++)
    {
        sum += scores[j];
    }

    float average = sum / (float) SIZE;
    printf("Average is %f\n", average);
}
