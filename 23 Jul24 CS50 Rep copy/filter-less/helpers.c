#include "helpers.h"
#include <math.h>

#define FOUR_BLOCK_SIZE 4
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average =
                (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = (BYTE) round(average);
            image[i][j].rgbtGreen = (BYTE) round(average);
            image[i][j].rgbtRed = (BYTE) round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // temp_color[0], temp_color[1] and temp_color[2] are sepiaBlue, sepiaGreen and sepiaRed
            // respectively
            double temp_color[3];
            temp_color[0] = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                            .131 * image[i][j].rgbtBlue;
            temp_color[1] = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                            .168 * image[i][j].rgbtBlue;
            temp_color[2] = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                            .189 * image[i][j].rgbtBlue;

            for (int k = 0; k < 3; k++)
            {
                if (temp_color[k] > 255)
                {
                    temp_color[k] = 255;
                }
            }

            image[i][j].rgbtBlue = (BYTE) round(temp_color[0]);
            image[i][j].rgbtGreen = (BYTE) round(temp_color[1]);
            image[i][j].rgbtRed = (BYTE) round(temp_color[2]);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height];

    if (width % 2 == 0)
    {
        int j = 0;
        while (j != width - j)
        {
            for (int i = 0; i < height; i++)
            {
                temp[i].rgbtBlue = image[i][j].rgbtBlue;
                temp[i].rgbtGreen = image[i][j].rgbtGreen;
                temp[i].rgbtRed = image[i][j].rgbtRed;

                image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
                image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
                image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;

                image[i][width - 1 - j].rgbtGreen = temp[i].rgbtGreen;
                image[i][width - 1 - j].rgbtBlue = temp[i].rgbtBlue;
                image[i][width - 1 - j].rgbtRed = temp[i].rgbtRed;
            }
            j++;
        }
        return;
    }

    else
    {
        int j = 0;
        while (j != width - 1 - j)
        {
            for (int i = 0; i < height; i++)
            {
                temp[i].rgbtBlue = image[i][j].rgbtBlue;
                temp[i].rgbtGreen = image[i][j].rgbtGreen;
                temp[i].rgbtRed = image[i][j].rgbtRed;

                image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
                image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
                image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;

                image[i][width - 1 - j].rgbtGreen = temp[i].rgbtGreen;
                image[i][width - 1 - j].rgbtBlue = temp[i].rgbtBlue;
                image[i][width - 1 - j].rgbtRed = temp[i].rgbtRed;
            }
            j++;
        }
        return;
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
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

    // "count" is the number of neighbors of each pixel INCLUDING itself; setting this to a default
    // value of 9
    float count[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            count[i][j] = 9;
        }
    }

    typedef struct
    {
        float rgbtBlue;
        float rgbtGreen;
        float rgbtRed;
    } sum;

    // "pixel_sum" is the sum of the original color values of the neighbors of the concerned pixel,
    // INCLUDING itself
    sum pixel_sum;
    pixel_sum.rgbtBlue = 0;
    pixel_sum.rgbtGreen = 0;
    pixel_sum.rgbtRed = 0;

    // "average" is the calculated average color value of each pixel, which will be assigned as the
    // new color value
    sum average[height][width];

    // Loops i and j iterate over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Loops k and l iterate over all the neighbors of each pixel, INCLUDING itself, forming
            // a 3x3 box
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (i - 1 + k < 0 || j - 1 + l < 0 || i - 1 + k >= height || j - 1 + l >= width)
                    {
                        count[i][j]--;
                    }
                    else
                    {
                        pixel_sum.rgbtBlue += copy[i - 1 + k][j - 1 + l].rgbtBlue;
                        pixel_sum.rgbtGreen += copy[i - 1 + k][j - 1 + l].rgbtGreen;
                        pixel_sum.rgbtRed += copy[i - 1 + k][j - 1 + l].rgbtRed;
                    }
                }
            }
            average[i][j].rgbtBlue = pixel_sum.rgbtBlue / count[i][j];
            average[i][j].rgbtGreen = pixel_sum.rgbtGreen / count[i][j];
            average[i][j].rgbtRed = pixel_sum.rgbtRed / count[i][j];

            if (average[i][j].rgbtBlue > 255)
            {
                average[i][j].rgbtBlue = 255;
            }
            else if (average[i][j].rgbtGreen)
            {
                average[i][j].rgbtGreen = 255;
            }
            else if (average[i][j].rgbtRed)
            {
                average[i][j].rgbtRed = 255;
            }
            // Assigning the image pixels the calculated average color values
            image[i][j].rgbtBlue = (BYTE) round(average[i][j].rgbtBlue);
            image[i][j].rgbtGreen = (BYTE) round(average[i][j].rgbtGreen);
            image[i][j].rgbtRed = (BYTE) round(average[i][j].rgbtRed);

            // Resetting the values "pixel_sum" for iterating over the next pixel's neighbors
            pixel_sum.rgbtBlue = 0;
            pixel_sum.rgbtGreen = 0;
            pixel_sum.rgbtRed = 0;
        }
    }
}
