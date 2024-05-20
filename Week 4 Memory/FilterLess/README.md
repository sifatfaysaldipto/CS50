## Function Details

### `void grayscale(int height, int width, RGBTRIPLE image[height][width])`
- Converts the input image to grayscale.
- Parameters:
    - `height`: Height of the image.
    - `width`: Width of the image.
    - `image`: 2D array representing the image pixels in RGB format.

### `void sepia(int height, int width, RGBTRIPLE image[height][width])`
- Converts the input image to sepia.
- Parameters:
    - `height`: Height of the image.
    - `width`: Width of the image.
    - `image`: 2D array representing the image pixels in RGB format.

### `void reflect(int height, int width, RGBTRIPLE image[height][width])`
- Reflects the input image horizontally.
- Parameters:
    - `height`: Height of the image.
    - `width`: Width of the image.
    - `image`: 2D array representing the image pixels in RGB format.

### `void blur(int height, int width, RGBTRIPLE image[height][width])`
- Applies a blur effect to the input image.
- Parameters:
    - `height`: Height of the image.
    - `width`: Width of the image.
    - `image`: 2D array representing the image pixels in RGB format.

## Usage
1. Include `helpers.h` in your C program.
2. Call the desired function with appropriate parameters to manipulate your image.

## Note
These functions assume that the input image is represented as a 2D array of `RGBTRIPLE` structs, where each struct contains `rgbtRed`, `rgbtGreen`, and `rgbtBlue` components representing the pixel color channels.