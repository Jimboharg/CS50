#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each row of pixels
    for (int row = 0; row < height; row++)
    {
        //loop through each pixel in row
        for (int pixel = 0; pixel < width; pixel++)
        {
            float sum = image[row][pixel].rgbtBlue + image[row][pixel].rgbtGreen + image[row][pixel].rgbtRed;
            float average = round(sum / 3);
            image[row][pixel].rgbtBlue = average;
            image[row][pixel].rgbtGreen = average;
            image[row][pixel].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each row of pixels
    for (int row = 0; row < height; row++)
    {
        //loop through each pixel in row
        for (int pixel = 0; pixel < width; pixel++)
        {
            float originalRed = image[row][pixel].rgbtRed;
            float originalGreen = image[row][pixel].rgbtGreen;
            float originalBlue = image[row][pixel].rgbtBlue;

            float sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            float sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            float sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

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

            image[row][pixel].rgbtBlue = sepiaBlue;
            image[row][pixel].rgbtGreen = sepiaGreen;
            image[row][pixel].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each row of pixels
    for (int row = 0; row < height; row++)
    {
        RGBTRIPLE Templine[width];
        //loop through each pixel in row
        for (int pixel = 0; pixel < width; pixel++)
        {
            //Copy each pixel to opposite end of templine array
            Templine[width - 1 - pixel].rgbtRed = image[row][pixel].rgbtRed;
            Templine[width - 1 - pixel].rgbtGreen = image[row][pixel].rgbtGreen;
            Templine[width - 1 - pixel].rgbtBlue = image[row][pixel].rgbtBlue;
        }
        //loop through and rewrite the image line with the value from Templine
        for (int newpixel = 0; newpixel < width; newpixel++)
        {
            image[row][newpixel].rgbtRed = Templine[newpixel].rgbtRed;
            image[row][newpixel].rgbtGreen = Templine[newpixel].rgbtGreen;
            image[row][newpixel].rgbtBlue = Templine[newpixel].rgbtBlue;
        }
    }
    return;
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //declare array to store blurred values so as not overwrite original image values whilst calculating averages
    RGBTRIPLE Tempgrid[height][width];

    float redsum = 0;
    float greensum = 0;
    float bluesum = 0;

    float validpixelcounter = 0;

    //loop through each row of pixels
    for (int row = 0; row < height; row++)
    {
        //loop through each pixel in row
        for (int pixel = 0; pixel < width; pixel++)
        {
            //loop through the 3 rows sandwiching the pixel
            for (int boxrow = row - 1; boxrow <= row + 1; boxrow++)
            {

                //loop through the 3 pixels in each of the above rows
                for (int boxpixel = pixel - 1; boxpixel <= pixel + 1; boxpixel++)
                {
                    //if cell is a valid cell then add to average figures
                    if (boxrow >= 0 && boxrow < height && boxpixel >= 0 && boxpixel < width)
                    {
                        redsum = redsum + image[boxrow][boxpixel].rgbtRed;
                        greensum = greensum + image[boxrow][boxpixel].rgbtGreen;
                        bluesum = bluesum + image[boxrow][boxpixel].rgbtBlue;
                        validpixelcounter ++;
                    }

                    if (boxrow == row + 1  && boxpixel == pixel + 1)
                    {
                        float averagered = round(redsum / validpixelcounter);
                        float averagegreen = round(greensum / validpixelcounter);
                        float averageblue = round(bluesum / validpixelcounter);

                        Tempgrid[row][pixel].rgbtRed = averagered;
                        Tempgrid[row][pixel].rgbtGreen = averagegreen;
                        Tempgrid[row][pixel].rgbtBlue = averageblue;

                        validpixelcounter = 0;
                        redsum = 0;
                        greensum = 0;
                        bluesum = 0;
                    }
                }
            }
        }
    }

    //loop through all pixels in tempgrid and copy over original image
    for (int copyrow = 0; copyrow < height; copyrow++)
    {

        for (int copypixel = 0; copypixel < width; copypixel++)
        {
            image[copyrow][copypixel].rgbtRed = Tempgrid[copyrow][copypixel].rgbtRed;
            image[copyrow][copypixel].rgbtGreen = Tempgrid[copyrow][copypixel].rgbtGreen;
            image[copyrow][copypixel].rgbtBlue = Tempgrid[copyrow][copypixel].rgbtBlue;
        }

    }
    return;
}
