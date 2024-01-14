#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int only_digits(string key);
string rotate(string text, int key);

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
        string plaintext = get_string("plaintext:  ");
        string ciphertext = rotate(plaintext, k);
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}

int only_digits(string key)
{
    bool verification = true;
    for(int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]))
        {
            verification = true;
        }
        else
        {
            verification = false;
        }
    }
    return verification;
}

string rotate(string text, int key)
{
    string cipher = "";
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
            cipher[i] = text[i];
        }
        printf("%s\n", cipher);
    }
    return cipher;
}

