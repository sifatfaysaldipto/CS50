#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check for proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover filename.raw\n");
        return 1;
    }

    // Open memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Create buffer to read data
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];

    // Counter for number of JPEGs found on the memory card
    int counter = 0;

    // Output file
    FILE *output = NULL;

    // Loop through the data on the card and read every block of 512 bytes into a buffer
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check if it's the start of a new JPEG
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            // Close previous file if it's open
            if (output != NULL)
            {
                fclose(output);
            }

            // Open new file to write
            char filename[8]; // Filename buffer
            sprintf(filename, "%03i.jpg", counter); // Format filename
            output = fopen(filename, "w"); // Open file for writing
            if (output == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                fclose(file);
                return 2;
            }

            // Increment JPEG counter
            counter++;
        }

        // If currently writing to a file, continue writing
        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    // Close remaining files
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(file);

    return 0;
}