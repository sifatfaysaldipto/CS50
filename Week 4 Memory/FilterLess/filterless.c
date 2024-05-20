#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int row = 0; row < height; row++)
    {
        // Loop through columns
        for (int column = 0; column < width; column++)
        {
            // Calculate average grayscale value for each pixel
            int avgGray = round((image[row][column].rgbtBlue + image[row][column].rgbtGreen + image[row][column].rgbtRed) / 3.0);

            // Assign grayscale values to all color channels
            image[row][column].rgbtRed = avgGray;
            image[row][column].rgbtGreen = avgGray;
            image[row][column].rgbtBlue = avgGray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int row = 0; row < height; row++)
    {
        // Loop through columns
        for (int column = 0; column < width; column++)
        {
            // Calculate sepia values for each color channel
            int sepiaRed = round(.393 * image[row][column].rgbtRed + .769 * image[row][column].rgbtGreen + .189 * image[row][column].rgbtBlue);
            int sepiaGreen = round(.349 * image[row][column].rgbtRed + .686 * image[row][column].rgbtGreen + .168 * image[row][column].rgbtBlue);
            int sepiaBlue = round(.272 * image[row][column].rgbtRed + .534 * image[row][column].rgbtGreen + .131 * image[row][column].rgbtBlue);

            // Cap sepia values at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Assign sepia values to corresponding color channels
            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int row = 0; row < height; row++)
    {
        // Loop through the first half of columns in each row
        for (int column = 0; column < width / 2; column++)
        {
            // Swap pixels from left to right
            RGBTRIPLE temp = image[row][column];
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store original pixel values
    RGBTRIPLE temp[height][width];

    // Copy original image to temporary image
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            temp[row][column] = image[row][column];
        }
    }

    // Loop through rows
    for (int row = 0; row < height; row++)
    {
        // Loop through columns
        for (int column = 0; column < width; column++)
        {
            // Initialize variables to store sums of color channels
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            // Counter to keep track of neighboring pixels
            float counter = 0;

            // Loop through surrounding pixels (3x3 grid)
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    // Check if neighboring pixel is within image bounds
                    if (row + i >= 0 && row + i < height && column + j >= 0 && column + j < width)
                    {
                        // Add color channel values to sums
                        sumRed += temp[row + i][column + j].rgbtRed;
                        sumGreen += temp[row + i][column + j].rgbtGreen;
                        sumBlue += temp[row + i][column + j].rgbtBlue;
                        counter++;
                    }
                }
            }

            // Assign blurred values to original image
            image[row][column].rgbtRed = round(sumRed / counter);
            image[row][column].rgbtGreen = round(sumGreen / counter);
            image[row][column].rgbtBlue = round(sumBlue / counter);
        }
    }
}