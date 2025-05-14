#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

bool only_letters(string input);

int main(int argc, string argv[])
{
    // Verify if the number of arguments is valid
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Verify if all characteres are letters
    if(!only_letters(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get the user input
    // string user_input = get_string("plaintext: ");

    // Run the cypher script

    // Return the cyphertext
}

bool only_letters(string input)
{

}
