#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: \n");
    }
    while(height <= 0 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = i; k > 0; k--)
        {
            printf("#");
        }
        printf("  ");
        for (int k = i; k > 0; k--)
        {
            printf("#");
        }
    printf("\n");
    }
}
