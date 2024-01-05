#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int c;
    do
    {
        c = get_int("Change owed: ");
    }
    while (c < 1);

    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;
    int counter = 0;

    while (c > 0)
    {
        if (c >= q)
        {
            c = c - q;
            counter++;
        }
        else if (c >= d)
        {
            c = c - d;
            counter++;
        }
        else if (c >= n)
        {
            c = c - n;
            counter++;
        }
        else if (c >= p)
        {
            c = c - p;
            counter++;
        }
        printf("%i", counter);
    }
}
