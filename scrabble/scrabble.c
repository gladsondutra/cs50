#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int get_scrabble_score(string input);
int scrabble_scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int main(void)
{
    string player_one_input = get_string("Player 1: ");
    int score_one = get_scrabble_score(player_one_input);

    string player_two_input = get_string("Player 2: ");
    int score_two = get_scrabble_score(player_two_input);

    if(score_one > score_two)
    {
        printf("Player 1 wins!\n");
    }
    else if(score_one < score_two)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_scrabble_score(string input)
{
    int score = 0;
    int length = strlen(input);

    for(int i = 0; i < length; i++)
    {
        char upper = toupper(input[i]);

        if(upper >= 'A' && upper <= 'Z')
        {
            score += scrabble_scores[upper - 'A'];
        }
    }
    return score;
}
