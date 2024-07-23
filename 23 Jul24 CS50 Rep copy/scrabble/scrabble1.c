#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Assigned global variable length which is updated during both user inputs
int length;
int point_counter(char array[]);
int main(void)
{
    // Declaring an array to store points
    int points[2] = {0, 0};

    // Getting input from Player-1
    string word = get_string("Player 1: ");
    length = strlen(word);

    // Converting lowercase to uppercase
    for(int i = 0; i < length; i++)
    {
        word[i] = toupper(word[i]);
    }

    // Calculating Player-1's points
    points[0] = point_counter(word);

    // Getting input from Player-2, word variable is updated
    word = get_string("Player 2: ");
    length = strlen(word);

    // Converting lowercase to uppercase
    for(int i = 0; i < length; i++)
    {
        word[i] = toupper(word[i]);
    }

    // Calculating Player-2's points
    points[1] = point_counter(word);

    // Declaration of final verdict
    if(points[0] > points [1])
    {
        printf("Player 1 wins!\n");
    }
    else if(points[1] > points[0])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

#define word array
int point_counter(char array[])
{
    // points variable defined locally
    int points = 0;

    for(int i = 0; i < length; i++)
    {
        if(word[i] == 'A')
        {
            points += 1;
        }
        else if(word[i] == 'B')
        {
            points += 3;
        }
        else if(word[i] == 'C')
        {
            points += 3;
        }
        else if(word[i] == 'D')
        {
            points += 2;
        }
        else if(word[i] == 'E')
        {
            points += 1;
        }
        else if(word[i] == 'F')
        {
            points += 4;
        }
        else if(word[i] == 'G')
        {
            points += 2;
        }
        else if(word[i] == 'H')
        {
            points += 4;
        }
        else if(word[i] == 'I')
        {
            points += 1;
        }
        else if(word[i] == 'J')
        {
            points += 8;
        }
        else if(word[i] == 'K')
        {
            points += 5;
        }
        else if(word[i] == 'L')
        {
            points += 1;
        }
        else if(word[i] == 'M')
        {
            points += 3;
        }
        else if(word[i] == 'N')
        {
            points += 1;
        }
        else if(word[i] == 'O')
        {
            points += 1;
        }
        else if(word[i] == 'P')
        {
            points += 3;
        }
        else if(word[i] == 'Q')
        {
            points += 10;
        }
        else if(word[i] == 'R')
        {
            points += 1;
        }
        else if(word[i] == 'S')
        {
            points += 1;
        }
        else if(word[i] == 'T')
        {
            points += 1;
        }
        else if(word[i] == 'U')
        {
            points += 1;
        }
        else if(word[i] == 'V')
        {
            points += 4;
        }
        else if(word[i] == 'W')
        {
            points += 4;
        }
        else if(word[i] == 'X')
        {
            points += 8;
        }
        else if(word[i] == 'Y')
        {
            points += 4;
        }
        else if(word[i] == 'Z')
        {
            points += 10;
        }
    }
    return points;
}
