#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int h;

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1);

    for (int i = 0; i < h; i++)
    {
        for (int j = 1; j < h - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf("  ");
        printf("\n");

        for (int l = 0; l < h - i; l++)
        {
            printf("#");
        }
    }
}
