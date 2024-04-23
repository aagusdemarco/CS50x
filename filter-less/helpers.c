#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels (2-dimensional matrix)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            // Average of RGB values in all pixels
             float avg_rgb = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
             avg_rgb = round(avg_rgb);

             // Update each pixel of the image
             image[i][j].rgbtRed = avg_rgb;
             image[i][j].rgbtGreen = avg_rgb;
             image[i][j].rgbtBlue = avg_rgb;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Extract each pixel's original RGB value
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Calculate sepia RGB values
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // Restrict sepia values to 255 MAX
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

            // Update each pixel
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        // Loop over half the width so values don't return to normal value after initial swapping
        for (int j = 0; j < width / 2; j++)
        {
            // Swap the pixels
            RGBTRIPLE buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the original image for reference
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0, green = 0, blue = 0, counter = 0;

            for (int k = i - 1; k < i + 2; k++)
            {
                for (int m = j - 1; m < j + 2; m++)
                {
                    if (k >= 0 && k < height && m >= 0 && m < width)
                    {
                        red += copy[k][m].rgbtRed;
                        green += copy[k][m].rgbtGreen;
                        blue += copy[k][m].rgbtBlue;
                        counter++;
                    }
                }
            }
            image[i][j].rgbtRed = round((red/counter));
            image[i][j].rgbtGreen = round((green/counter));
            image[i][j].rgbtBlue = round((blue/counter));
        }
    }
    return;
}
