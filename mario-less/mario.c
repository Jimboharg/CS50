#include <stdio.h>
#include <cs50.h>
int main(void)

{
    //ask user for pyramid height as integer between 0 and 23
    //do while loop as it runs atleast once to capture input.
    //if wrong input given (less than 1, more than 8) then loops to ask again.
    int height;

    do
    {
        height = get_int("Height of pyramid (max 8):");
    }
    while (height <= 0 || height > 8);

    //main loop that loops until it reaches the height inputted
    for (int i = 0; i < height; i++)
    {
        //nested loop for spaces
        for (int spaces = 2; spaces <= height - i; spaces ++)
        {
            printf(" ");
        }

        //nested loop for hashtags
        for (int tags = 0; tags < i + 1; tags ++)
        {
            printf("#");
        }
        printf("\n");
    }
}