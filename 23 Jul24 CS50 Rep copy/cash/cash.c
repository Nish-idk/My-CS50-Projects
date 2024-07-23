// Gives the least amount of coins required for a given amount of change

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change_owed;
    // Ensuring negative change is not entered
    do
    {
        change_owed = get_int("change in cents: ");
    }
    while (change_owed < 0);

#define PENNY 1
#define NICKEL 5
#define DIME 10
#define QUARTER 25

    // Number of Quarters, Dimes, Nickels and Pennies required
    int no_Quarters = change_owed / QUARTER;
    change_owed -= no_Quarters * QUARTER;

    int no_Dimes = change_owed / DIME;
    change_owed -= no_Dimes * DIME;

    int no_Nickels = change_owed / NICKEL;
    change_owed -= no_Nickels * NICKEL;

    int no_Pennies = change_owed;

    // Total number of coins required
    int result = no_Quarters + no_Dimes + no_Nickels + no_Pennies;

    printf("The least number of coins required is %i\n", result);
    printf("%i quarters, %i dimes, %i nickels and %i pennies\n", no_Quarters, no_Dimes, no_Nickels,
           no_Pennies);
}
