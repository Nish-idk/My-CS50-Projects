// Determines reading grade level

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get text from user
    string text = get_string("text: ");
    int length = strlen(text);

    // Count number of words in text
    int spaces = 0;
    for (int i = 0; i < length; i++)
    {
        if (isblank(text[i]))
        {
            spaces++;
        }
    }
    int words = spaces + 1;

    // Count number of letters
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
        }
    }

    // Count number of sentences
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float L = (float) letters * 100 / (float) words;
    float S = (float) sentences * 100 / (float) words;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    double grade = round(index);

    if ((int) grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((int) grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) grade);
    }
}
