#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("text: ");

    int i = 0;
    while(text[i] != '\0')
    {
        i++;
    }
    return i;

    printf("length is %i\n", i);
    printf("okay\n");
}
