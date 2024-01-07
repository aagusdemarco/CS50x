#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    long length;
    //15 digitos y 34... o 37...
    //13 o 16 digitos y 4...
    //16 digitos y 51..., 52..., 53..., 54..., 55...
    int counter = 0;

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
    printf("%i\n", counter - 2);
    int shit = card / (10 * (counter - 2));
    printf("%i\n", shit);

    if (counter == 15 && (card / (10 * (counter - 2)) == 34 || card / (10 * (counter - 2)) == 37))
    {
        printf("AMEX\n");
    }
    else if ((counter == 16 || counter == 13) && card / (10 * (counter - 2)) == 4)
    {
        printf("VISA\n");
    }
    else if (counter == 16 && (card / (10 * (counter - 2)) == 51 || card / (10 * (counter - 2)) == 52 || card / (10 * (counter - 2)) == 53 || card / (10 * (counter - 2)) == 54))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
