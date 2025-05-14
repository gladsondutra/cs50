#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int payment;
    int coins = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    do
    {
        payment = get_int("Change owed: ");
    }
    while(payment < 0);

    while(payment > 0)
    {
        if(payment - quarter >= 0)
        {
            payment -= quarter;
            coins++;
        }
        else if(payment - dime >= 0)
        {
            payment -= dime;
            coins++;
        }
        else if(payment - nickel >= 0)
        {
            payment -= nickel;
            coins++;
        }
        else
        {
            payment -= penny;
            coins++;
        }
    }

    printf("%i\n", coins);
}
