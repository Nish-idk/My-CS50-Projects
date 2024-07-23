#include <cs50.h>
#include <stdio.h>

int strrlen(string text);
int main(void)
{
    string text = get_string("text: ");

    printf("length is %i\n", strrlen(text));
}

int strrlen(string text)
{
    int i = 0;
    while(text[i] != '\0')
    {
        i++;
    }
    return i;
}
 