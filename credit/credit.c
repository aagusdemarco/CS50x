#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    //15 digitos y 34... o 37...
    //13 o 16 digitos y 4...
    //16 digitos y 51..., 52..., 53..., 54..., 55...
    int counter = 0;

    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    while (card != 0)
    {
        card = card / 10;
        counter++;
    }

    if (counter == 15 && (card / (counter - 2) == 34 || card / (counter - 2) == 37))
    {
        printf("AMEX\n");
    }
}
