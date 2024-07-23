// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CITIES 10
int FLAG = 0;

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);
void swap(avg_temp *small_city, avg_temp *big_city);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    for (int i = 1; i < NUM_CITIES; i++)
    {
        if (temps[i - 1].temp < temps[i].temp)
        {
            swap(&temps[i - 1], &temps[i]);
        }
        else
        {
            FLAG++;
        }
    }
    if (FLAG == 9)
    {
        return;
    }
    FLAG = 0;
    sort_cities();
    return;
}

void swap(avg_temp *small_city, avg_temp *big_city)
{
    avg_temp store_city = *small_city;
    *small_city = *big_city;
    *big_city = store_city;
    return;
}

