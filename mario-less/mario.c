#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while(h < 1);

    for(int i = 0; i < h; i++)
    {
        for(int j = 1; j < h - 1; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
