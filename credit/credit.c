#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card;
    long length;
    //15 digitos y 34... o 37...
    //13 o 16 digitos y 4...
    //16 digitos y 51..., 52..., 53..., 54..., 55...
    int counter = 0;
    int sum1;
    int sum2;
    int mod1;
    int mod2;
    int dble1;
    int dble2;
    int total = 0;

    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    length = card;
    while (length != 0)
    {
        length = length / 10;
        counter++;
    }

    if (length != 13 && length != 15 && length != 16){
        printf("INVALID\n");
    }

    do
    {
        mod1 = card % 10;
        card = card / 10;
        sum1 = sum1 + mod1;

        mod2 = card % 10;
        card = card / 10;

        mod2 = mod2 * 2;
        dble1 = mod2 % 10;
        dble2 = mod2 / 10;
        sum2 = sum2 + dble1 + dble2;
    }
    while (card > 0);

    total = sum1 + sum2;
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }

    if ((counter == 15) && (card / pow(10, counter - 2) == 34 || card / pow(10, counter - 2) == 37))
    {
        printf("AMEX\n");
    }
    else if (counter == 16 && (card / pow(10, counter - 2) == 51 || card / pow(10, counter - 2) == 52))

}
