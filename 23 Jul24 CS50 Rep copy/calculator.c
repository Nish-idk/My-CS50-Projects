#include<stdio.h>
#include<cs50.h>

int add(int a, int b);
int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    z = add(x, y);
    printf("%i\n", z);
}

int add(int a, int b)
{
    return a + b;
}
