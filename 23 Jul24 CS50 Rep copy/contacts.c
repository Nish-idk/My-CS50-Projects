#include<stdio.h>
#include<cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("What's your age? ");
    int phone_number = get_int("What's your phone number? ");

    printf("Name: %s, Age: %i, Phone Number: %i\n", name, age, phone_number);
}
