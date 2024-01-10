#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string convert_upper(string word);
int get_score(string upperword);
void winner(int score1, int score2);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    string upperword1 = convert_upper(word1);
    string upperword2 = convert_upper(word2);

    int score1 = get_score(upperword1);
    int score2 = get_score(upperword2);

    winner(score1, score2);
}

string convert_upper(string word)
{
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        word[i] = toupper(word[i]);
    }
    return word;
}

int get_score(string upperword)
{
    int score = 0;
    int length = strlen(upperword);
    if (length == 0)
    {
        return 1;
    }
    for (int i = 0; i < length; i++)
    {
        if (upperword[i] > 64 && upperword[i] < 91)
        {
            score = score + upperword[i];
        }
    }
    return score;
}

void winner(int score1, int score2)
{
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
