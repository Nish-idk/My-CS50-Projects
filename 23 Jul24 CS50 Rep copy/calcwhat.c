#include<stdio.h>
#include<cs50.h>

int main(void)
{
    x = get_int("x: ");
    y = get_int("y: ");

    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}
