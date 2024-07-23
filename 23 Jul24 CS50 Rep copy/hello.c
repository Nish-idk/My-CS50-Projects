#include<stdio.h>
#include<cs50.h>
int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s!\n", name);
    string place = get_string("Where are you from? ");
    printf("Welcome, %s of %s.\n", name, place);
}
