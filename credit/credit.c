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




}
