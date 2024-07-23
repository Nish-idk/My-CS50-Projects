#include<stdio.h>
#include<cs50.h>

void add(void);
void subtract(void);
int main(void)
{
    char operation = get_char("add or subtract? ");
    if (operation == 'a')
    {
        add();
    }
    else if (operation == 's')
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
