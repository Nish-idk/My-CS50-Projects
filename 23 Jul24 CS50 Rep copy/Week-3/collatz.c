#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int main(void)
{
    int n = get_int ("n = ");
    if (n < 1)
    {
        printf("wrong usage\n");
        return 1;
    }
    else
    {
        printf("The number of steps is %i\n", collatz(n));
    }
}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n - (n / 2 * 2) == 0)
    {
        n /= 2;
        return 1 + collatz(n);
    }
    else
    {
        n = 3 * n + 1;
        return 1 + collatz(n);
    }
}

