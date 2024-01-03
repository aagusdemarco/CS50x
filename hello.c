#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}

if (x < y)
{
    int x = get_int("What's the value of x? ");
    int y = get_int("What's the value of y? ");
    printf("x is less then y\n");
}
else if (x > y)
{
    printf("x is greater then y\n");
}
else if (x == y)
{
    printf("x is equeal to y\n");
}
