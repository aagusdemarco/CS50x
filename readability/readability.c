#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < length; i++)
    {
        // letter counter
        char c = text[i];
        if (isalpha(c) != 0)
        {
            letters++;
        }

        // word counter
        if (c == ' ')
        {
            words++;
        }

        // sentence counter
        if (c == '.' || c == '?' || c == '!')
        {
            sentences++;
        }

        // last word
        words++;
    }

    int L = (letters / words) * 100;
    int S = (sentences / words) * 100;
    int index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

