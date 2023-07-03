#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask user for name
    string name = get_string("Hello, what is your name \n");

    // take user's name and print greeting
    printf("hello, %s\n", name);
}