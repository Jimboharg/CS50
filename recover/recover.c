#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//declare global variables
FILE *image;
char filename[8];
bool fileopen = false;
int photocount = -1;

int main(int argc, char *argv[])
{
    //check input is correct
    if (argc != 2)
    {
        printf("Please enter only one input filename");
        return 1;
    }


    //open memory card file for reading
    FILE *card = fopen(argv[1], "r");

    //create buffer to hold each 512 byte block
    unsigned char buffer[512];

    //loop through card while return of fread matches number of blocks to read google "fread" to see return of function
    while (fread(&buffer, 512, 1, card) == 1)
    {
        //if first 4 bytes of 512 block match that of a jpeg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if a file is already open then close the file and set the fileopen bool to false
            if (fileopen == true)
            {
                fclose(image);
                fileopen = false;
            }

            //sequentially name and open a new jpeg file to store image then set fileopen variable to true
            photocount++;
            sprintf(filename, "%03i.jpg", photocount);
            //printf("%s", filename);
            image = fopen(filename, "w");
            fileopen = true;
        }

        //if there is a jpeg file open then write a 512 byte block on each iteration of while loop
        if (fileopen == true)
        {
            fwrite(&buffer, 512, 1, image);

        }
    }
    //at end of loop close image file
    fclose(image);

    //at end of loop close the mem card file and exit the program
    fclose(card);
    return 0;
}

