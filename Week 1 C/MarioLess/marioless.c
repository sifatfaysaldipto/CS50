#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for input to determine the height of the pyramid
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while (size <= 0 || size >= 9); // Ensure the size is between 1 and 8

    // Loop to print the Mario pyramid
    for (int i = 1; i <= size; i++)
    {
        // Inner loop to print spaces before the blocks on each line
        for (int k = size - 1; k >= i; k--)
        {
            printf(" ");
        }

        // Inner loop to print the blocks of the pyramid
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        // Move to the next line after printing the blocks for the current line
        printf("\n");
    }
}
