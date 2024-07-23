#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Making copies of all pixels to store their original color values
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    // Creating Gx matrix
    int Gx_MATRIX[3][3];
    for (int i = 0; i < 3; i++)
    {
        Gx_MATRIX[i][1] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        Gx_MATRIX[i][0] = -1;
    }
    Gx_MATRIX[1][0] = -2;
    for (int i = 0; i < 3; i++)
    {
        Gx_MATRIX[i][2] = 1;
    }
    Gx_MATRIX[1][2] = 2;

    // Creating Gy matrix
    int Gy_MATRIX[3][3];
    for (int j = 0; j < 3; j++)
    {
        Gy_MATRIX[1][j] = 0;
    }
    for (int j = 0; j < 3; j++)
    {
        Gy_MATRIX[0][j] = -1;
    }
    Gy_MATRIX[0][1] = -2;
    for (int j = 0; j < 3; j++)
    {
        Gy_MATRIX[2][j] = 1;
    }
    Gy_MATRIX[2][1] = 2;

    // Gx and Gy values of each pixel (to calculate Gx^2 + Gy^2)
    typedef struct
    {
        int rgbtBlue;
        int rgbtGreen;
        int rgbtRed;
    }
    intRGB;
    intRGB Gx[height][width];
    intRGB Gy[height][width];

    // Setting Gx and Gy values of each pixel to a default value of 0
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Gx[i][j].rgbtBlue = 0;
            Gx[i][j].rgbtGreen = 0;
            Gx[i][j].rgbtRed = 0;
            Gy[i][j].rgbtBlue = 0;
            Gy[i][j].rgbtGreen = 0;
            Gy[i][j].rgbtRed = 0;
        }
    }

    // Final color values of each pixel
    intRGB int_color_value[height][width];

    // Loops i and j iterate over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            /* Loops k and l iterate over all the neighbors of each pixel, INCLUDING itself, forming a 3x3 box.
               This set of loops also iterates over each element of Gx_MATRIX and Gy_MATRIX */
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (i - 1 + k < 0 || j - 1 + l < 0 || i - 1 + k >= height || j - 1 + l >= width)
                    {
                        continue;
                    }
                    else
                    {
                        // Calculating each pixel's Gx value
                        Gx[i][j].rgbtBlue += copy[i - 1 + k][j - 1 + l].rgbtBlue * Gx_MATRIX[k][l];
                        Gx[i][j].rgbtGreen += copy[i - 1 + k][j - 1 + l].rgbtGreen * Gx_MATRIX[k][l];
                        Gx[i][j].rgbtRed += copy[i - 1 + k][j - 1 + l].rgbtRed * Gx_MATRIX[k][l];

                        // Calculating each pixel's Gy value
                        Gy[i][j].rgbtBlue += copy[i - 1 + k][j - 1 + l].rgbtBlue * Gy_MATRIX[k][l];
                        Gy[i][j].rgbtGreen += copy[i - 1 + k][j - 1 + l].rgbtGreen * Gy_MATRIX[k][l];
                        Gy[i][j].rgbtRed += copy[i - 1 + k][j - 1 + l].rgbtRed * Gy_MATRIX[k][l];
                    }
                }
            }
            // Calculating final color value of each pixel using formula
            int_color_value[i][j].rgbtBlue = (int) round(sqrt(pow(Gx[i][j].rgbtBlue, 2) + pow(Gy[i][j].rgbtBlue, 2)));
            int_color_value[i][j].rgbtGreen = (int) round(sqrt(pow(Gx[i][j].rgbtGreen, 2) + pow(Gy[i][j].rgbtGreen, 2)));
            int_color_value[i][j].rgbtRed = (int) round(sqrt(pow(Gx[i][j].rgbtRed, 2) + pow(Gy[i][j].rgbtRed, 2)));

            // Capping color values at 255
            if (int_color_value[i][j].rgbtBlue > 255)
            {
                int_color_value[i][j].rgbtBlue = 255;
            }
            if (int_color_value[i][j].rgbtGreen > 255)
            {
                int_color_value[i][j].rgbtGreen = 255;
            }
            if (int_color_value[i][j].rgbtRed > 255)
            {
                int_color_value[i][j].rgbtRed = 255;
            }

            // Assigning final color values to the actual image pixels
            image[i][j].rgbtBlue = int_color_value[i][j].rgbtBlue;
            image[i][j].rgbtGreen = int_color_value[i][j].rgbtGreen;
            image[i][j].rgbtRed = int_color_value[i][j].rgbtRed;
        }
    }
}
