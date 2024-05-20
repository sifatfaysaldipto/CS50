#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare height variable
    int height;

    // Get user input for the height of the pyramid
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Ensure height is between 1 and 8


    // Outer loop to iterate over each line of the pyramid
    for (int line = 0; line < height; line++)
    {
        // Inner loop to print spaces before the blocks on each line
        for (int space = height - 1; space > line; space--)
        {
            printf(" ");
        }

        // Print the left blocks of the pyramid
        for (int left_blocks = 0; left_blocks <= line; left_blocks++)
        {
            printf("#");
        }

        // Print the two spaces between the blocks
        printf("  ");

        // Print the right blocks of the pyramid
        for (int right_blocks = 0; right_blocks <= line; right_blocks++)
        {
            printf("#");
        }

        // Move to the next line after printing the blocks for the current line
        printf("\n");
    }
}