#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card;
    long length;
    int counter = 0;
    int sum1 = 0;
    int sum2 = 0;
    int mod1;
    int mod2;
    int dble1;
    int dble2;
    int total = 0;
    long startnum;

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

    startnum = card;
    do
    {
        startnum = startnum / 10;
    }
    while (startnum > 100);

    if ((startnum / 10 == 5) && (0 < startnum % 10 && startnum % 10 < 6)))
    {
        printf("MASTERCARD\n");
    }
    else if ((startnum / 10 == 3) && (startnum % 10 == 4 || startnum % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (startnum / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
