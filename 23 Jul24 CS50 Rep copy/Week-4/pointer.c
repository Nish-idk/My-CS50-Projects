#include <stdio.h>

int main(void)
{
    typedef char * string;
    char *s = "HI!";
    string n = "Bye\n";
    printf("%s, %s\n", s, n);
}
