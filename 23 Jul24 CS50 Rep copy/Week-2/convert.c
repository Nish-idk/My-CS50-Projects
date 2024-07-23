// Converts lowercase to uppercase
#include <cs50.h>
#include <stdio.h>

int main(void)
{   // get text input from user
    string text = get_string("text: ");

    // go through each char of string
    int i = 0;
    while(text[i] != '\0')
    {
        i++;
        if(text[i - 1] >= 'a' && text[i - 1] <= 'z')
        {
            text[i - 1] -= 32;
        }
    }
    //print out updated text input
    printf("%s\n", text);
}
