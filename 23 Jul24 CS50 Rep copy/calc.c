#include<stdio.h>
#include<cs50.h>

void add(void);
void subtract(void);
int main(void)
{
    string operation = get_string("add or subtract? ");
    if (operation == "add")
    {
        add();
    }
    else if (operation == "subtract")
    {
        subtract();
    }
}

void add(void)
{
    int x = get_int("x =  ");
    int y = get_int("y =  ");
    int answer = x + y;
    printf("%i\n", answer);
}

void subtract(void)
{
    int x = get_int("x =  ");
    int y = get_int("y =  ");
    int answer = x - y;
    printf("%i\n", answer);
}
