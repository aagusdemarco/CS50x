#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    int amex; //15 digitos y 34... o 37...
    int visa; //13 o 16 digitos y 4...
    int master; //16 digitos y 51..., 52..., 53..., 54..., 55...
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
}
