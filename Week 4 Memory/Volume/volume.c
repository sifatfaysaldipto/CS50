#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cs50.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb"); // Open input file in binary mode
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb"); // Open output file in binary mode
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input); // Close input file before returning
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    uint8_t header[HEADER_SIZE];

    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Read samples from input file and write updated data to output file
    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Update volume
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
    return 0; // Return 0 indicating successful execution
}