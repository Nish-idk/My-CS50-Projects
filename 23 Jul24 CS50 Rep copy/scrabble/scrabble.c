// Assigns scores to inputted words

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Assigning points to each alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Initializing each player's points
int points[] = {0, 0};

int main(void)
{
    // Getting inputs from both players
    string word[2];
    for (int i = 0; i < 2; i++)
    {
        word[i] = get_string("word: ");
    }

    // Calculating points
    int k;
    for (k = 0; k < 2; k++)
    {
        for (int i = 0, length = strlen(word[k]); i < length; i++)
        {
            if (ispunct(word[k][i]))
            {
                word[k][i] = '\0';
            }
            else
            {
                word[k][i] = toupper(word[k][i]);
            }
        }

        for (int i = 0, length = strlen(word[k]); i < length; i++)
        {
            int j = word[k][i] - 'A';
            points[k] += POINTS[j];
        }
    }

    // Declaring final verdict
    if (points[0] > points[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (points[1] > points[0])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
