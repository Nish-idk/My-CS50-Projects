#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int x = get_int("x = ");
    int y = get_int("y = ");

    if (x>y)
    {
        printf("%i is greater than %i.\n",x , y);
    }

    if (x<y)
    {
        printf("%i is less than %i.\n",x , y);
        printf("nice\n");
    }

    if (x == y)
    {
        printf("x equals y.\n");
    }
}
