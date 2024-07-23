#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int ("ODD: ");
    int N = n - (n / 2 * 2);
    printf("N = %i\n", N);
}
