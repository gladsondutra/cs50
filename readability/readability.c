#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

float readability_test(string phrase);

int main(void)
{
    string input = get_string("Text: ");

    int score = readability_test(input);
    if(score < 0)
    {
        printf("Before Grade 1\n");
    }
    else if(score >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", score);
    }
}

float readability_test(string phrase)
{
    float total_letters = 0.0;
    float total_words = 0.0;
    float total_sentences = 0.0;
    int length = strlen(phrase);

    for(int i = 0; i < length; i++)
    {
        if(toupper(phrase[i]) >= 'A' &&  toupper(phrase[i]) <= 'Z')
        {
            total_letters++;
        }
        if(phrase[i] == ' ')
        {
            total_words++;
        }
        if(phrase[i] == '!' || phrase[i] == '.' || phrase[i] == '?')
        {
            total_sentences++;
        }
    }
    total_words += 1;

    float L = ((float)total_letters / (float)total_words) * 100; // Average number of letters per 100 words in the text
    float S = ((float)total_sentences / (float)total_words) * 100;; // Average number of sentences per 100 words in the text
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    return index;
}
