#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average of RGB values for grayscale
            int rgbt = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // Set each color channel to the grayscale value
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rgbt;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each row of the image
    for (int i = 0; i < height; i++)
    {
        // Loop through each column until the midpoint
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels symmetrically across the vertical axis
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store blurred values
    RGBTRIPLE temp[height][width];

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumBlue = 0, sumGreen = 0, sumRed = 0;
            float counter = 0;

            // Loop through neighboring pixels in a 3x3 grid
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    // Check if the neighboring pixel is within the image boundaries
                    if (i + r >= 0 && i + r < height && j + c >= 0 && j + c < width)
                    {
                        // Accumulate RGB values and increment counter
                        sumBlue += image[i + r][j + c].rgbtBlue;
                        sumGreen += image[i + r][j + c].rgbtGreen;
                        sumRed += image[i + r][j + c].rgbtRed;
                        counter++;
                    }
                }
            }

            // Compute average RGB values and assign to temporary image
            temp[i][j].rgbtBlue = round(sumBlue / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    // Copy blurred image from temporary image to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store edge-detected values
    RGBTRIPLE temp[height][width];

    // Define Sobel operator kernels
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxBlue = 0, gyBlue = 0, gxGreen = 0, gyGreen = 0, gxRed = 0, gyRed = 0;

            // Loop through neighboring pixels in a 3x3 grid
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    // Check if the neighboring pixel is within the image boundaries
                    if (i + r >= 0 && i + r < height && j + c >= 0 && j + c < width)
                    {
                        // Apply Sobel operator to each color channel
                        gxBlue += image[i + r][j + c].rgbtBlue * gx[r + 1][c + 1];
                        gyBlue += image[i + r][j + c].rgbtBlue * gy[r + 1][c + 1];
                        gxGreen += image[i + r][j + c].rgbtGreen * gx[r + 1][c + 1];
                        gyGreen += image[i + r][j + c].rgbtGreen * gy[r + 1][c + 1];
                        gxRed += image[i + r][j + c].rgbtRed * gx[r + 1][c + 1];
                        gyRed += image[i + r][j + c].rgbtRed * gy[r + 1][c + 1];
                    }
                }
            }

            // Compute gradient magnitude for each color channel
            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            // Cap values to 255 if they exceed
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    // Copy edge-detected image from temporary image to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}