#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");
    if (age >= 18)
    {
        printf("%s is not authorized to proceed.\n", name);
    }
    else
    {
        printf("%s is not authorized to proceed.\n", name);
    }
}
