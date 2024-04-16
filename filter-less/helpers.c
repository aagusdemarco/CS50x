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
             int avg_rgb = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
             avg_rgb = round(avg_rgb);

             // Index the RGB values to each pixel of the image
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
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
