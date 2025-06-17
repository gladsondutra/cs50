#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

bool validation(string input);
void encipher(string cypher, string input);

int main(int argc, string argv[])
{

    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if(validation(argv[1]) == 0)
    {
        return 1;
    }


    string user_input = get_string("plaintext: ");

    printf("ciphertext: ");
    encipher(argv[1], user_input);
    printf("\n");
}

bool validation(string input)
{
    int length = strlen(input);

    if(length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for(int i = 0; i < length; i++)
    {
        if(isalpha(input[i]) == 0)
        {
            printf("Key must have only alphabetical characters.\n");
            return false;
        }
    }

    int seen_letters[26] = {0};

    for(int i = 0; i < 26; i++)
    {
        char c = tolower(input[i]);
        int index = c - 'a';

        if(seen_letters[index])
        {
            printf("Key must not have repeated characters.\n");
            return false;
        }
        seen_letters[index] = 1;
    }

    return true;
}

void encipher(string cypher, string input)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int input_length = strlen(input);
    int alphabet_length = strlen(alphabet);

    for(int i = 0; i < input_length; i++)
    {
        if(ispunct(input[i]) || isdigit(input[i]) || isblank(input[i]))
        {
            printf("%c", input[i]);
        }
        for(int j = 0; j < alphabet_length; j++)
        {
            if(tolower(input[i]) == tolower(alphabet[j]))
            {
                if(islower(input[i]))
                {
                    printf("%c", tolower(cypher[j]));
                }
                if(isupper(input[i]))
                {
                    printf("%c", toupper(cypher[j]));
                }
            }

        }
    }
}
