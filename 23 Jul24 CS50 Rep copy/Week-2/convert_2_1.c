#include <cs50.h>
#include <stdio.h>
#include <string.h>

string convert(string text);
int main(void)
{
    string input = get_string("Input: ");

    printf("Output: \n");
    for(int j = 0, n = strlen(input); j < n; j++)
    {
        printf("%c\n", convert(input)[j]);
    }

    printf("\n");
}

string convert(string text)
{
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] -= 32;
        }
    }
    return text;
}
