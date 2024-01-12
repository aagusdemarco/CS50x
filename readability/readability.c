#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
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
    }

    // last word
    words++;

    float L = (letters / (float) words) * 100;
    float S = (sentences / (float)words) * 100;
    float fl_index = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(fl_index);


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
