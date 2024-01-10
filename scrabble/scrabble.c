#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int convert_upper(string word);
int get_score(string upperword);

int main(void)
{
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int upperword1 = convert_upper(word1);
    int upperword2 = convert_upper(word2);

    int score1 = get_score(upperword1);
    int score2 = get_score(upperword2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

string convert_upper(string word)
{
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        word[i] = toupper(word[i]);
        printf("%s\n", word);
        return word;
    }
}

int get_score(string upperword)
{
    int score = 0;
    int length = strlen(upperword);
    for (int i = 0; i < length; i++)
    {
        score = score + points[upperword[i] - 65];
        return score;
    }
}
