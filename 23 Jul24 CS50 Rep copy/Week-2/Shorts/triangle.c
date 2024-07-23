#include <cs50.h>
#include <stdio.h>

int triangle(int x, int y, int z);
int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    int z = get_int("z: ");

    printf("%i\n", triangle(x, y, z));
}

int triangle(int x, int y, int z)
{
    if(x + y > z && x + z > y && y + z > x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
