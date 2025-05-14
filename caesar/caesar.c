#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string input);
char rotate(char input, int value);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if(!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int digit = atoi(argv[1]);
    string user_input = get_string("plaintext: ");

    int length = strlen(user_input);
    printf("ciphertext: ");
    for(int i = 0; i < length; i++)
    {
        printf("%c", rotate(user_input[i], digit));
    }
    printf("\n");
    return 0;
}

bool only_digits(string input)
{
    int length = strlen(input);
    for(int i = 0; i < length; i++)
    {
        if(!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char input, int value)
{
    if(toupper(input) < 'A' || toupper(input) > 'Z')
    {
        return input;
    }

    if(isupper(input) == 0)
    {
        int counter = value;
        while(counter > 0)
        {
            if(input == 'z')
            {
                input = 'a';
            }
            else
            {
                input++;
            }
            counter--;
        }
    }
    else
    {
        int counter = value;
        while(counter > 0)
        {
            if(input == 'Z')
            {
                input = 'A';
            }
            else
            {
                input++;
            }
            counter--;
        }
    }

    return input;
}


