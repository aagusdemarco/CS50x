#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long amex; //15 digitos y 34... o 37...
    long visa; //13 o 16 digitos y 4...
    long master; //16 digitos y 51..., 52..., 53..., 54..., 55...
    int counter = 0;

    do
    {
        long card = get_long("Number: ");
    }
    while(card < 0);

    
}
