#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Input: ");

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] -= 32;
        }
    }

    printf("Output: \n");
    for(int j = 0, n = strlen(text); j < n; j++)
    {
        printf("%c\n", text[j]);
    }

    printf("\n");
}
