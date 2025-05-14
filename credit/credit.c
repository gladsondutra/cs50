#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // long card_number = 4012888888881881;
    long card_number = get_long("Number: \n");
    int counter = 0;
    int odd_positions = 0;
    int even_positions = 0;
    long first_digit = 0;
    long first_two_digits = 0;
    long temp = card_number;

    while(temp > 0)
    {
        int digit = temp % 10;

        if(counter % 2 == 0){
            even_positions += digit;
        }
        if(counter % 2 == 1)
        {
            int product = digit  * 2;
            odd_positions += product % 10 + product / 10;
        }

        if(temp < 100 && temp >= 10)
        {
            first_two_digits = temp;
        }
        if (temp < 10)
        {
            first_digit = temp;
        }

        temp /= 10;
        counter++;
    }

    // [X] AMEX start with 34 or 37 -- uses 15-digit numbers
    // [X] MASTERCARD start with 51, 52, 53, 54, or 55 -- uses 16-digit numbers
    // [X] VISA start with 4 -- uses 13-digit numbers
    // [X] VISA start with 4 -- uses 16-digit numbers

    if((odd_positions + even_positions) % 10 == 0)
    {
        if(counter == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if(counter == 16 && (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if((counter == 16 || counter == 13) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
