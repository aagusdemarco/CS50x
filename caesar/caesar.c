#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]);
        return 0;
    }
}

int only_digits(string key)
{
    for(int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}

int rotate(char cc, int key)
{

}

