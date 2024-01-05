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
        printf(" ");
        for(int j = 0; j < h; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
