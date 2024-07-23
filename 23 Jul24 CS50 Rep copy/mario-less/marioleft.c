#include<stdio.h>
#include<cs50.h>

int main(void)
{
   int height = get_int("height: ");

for (int j= 0; j < height; j++) //make 'height' number of levels
{
    for(int i = 0; i < j + 1; i++) //make desired length of levels
    {
        printf("#");
    }
    printf("\n");
}

}



