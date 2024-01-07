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
    printf("%li", card / 10000000000000);

    if (counter == 15 && (card / 10000000000000 == 34 || card / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
}
