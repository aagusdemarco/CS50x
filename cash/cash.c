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
            counter += 1;
        }
        else if (c >= d && c < q)
        {
            c = c - d;
            counter += 1;
        }
        else if (c >= n && c < d)
        {
            c = c - n;
            counter += 1;
        }
        else if (c >= p && c < n)
        {
            c = c - p;
            counter += 1;
        }
    }
    printf("%i\n", counter);
}
