#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string key);
int rotate(string text, int key);

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

    string plaintext = get_string("plaintext:  ");
    string ciphertext = rotate(plaintext, k);
    printf("ciphertext: %s\n", ciphertext);
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

int rotate(string text, int key)
{
    string cipher = text;
    for (int i = 0; i > strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            cipher[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower(text[i]))
        {
            cipher[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
        else
        {
            cipher[i] = text[i]
        }
    }
    return cipher;
}

