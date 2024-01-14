#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(string key);

int main(int argc, string argv[])
{
    if (argc > 3 && argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv[1] == true))
    {
        int only_digits(string key)
    }
}

int only_digits(string key)
{
    for(int i = 0; i < strlen(key); i++)
    {
        if (key[i] > 47 && key[i] < 58)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


