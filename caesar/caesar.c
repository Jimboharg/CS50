#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//takes input from command line eg ""./caesar 13"
int main(int argc, string argv[])
{
    string c;
    //checks that there is only one input after ./caesar also checks that there is atleast one input after ./caesar
    // note that running the program - "./caesar" counts as one argc
    if (argc > 2 || argc == 1)

        //if more than one input after ./caesar or no inputs then give error message
    {
        printf("Usage: ./caesar key\n");
        //return 1 to exit.
        return 1;
    }

    else
        //iterate through the key to check that the letters are digits (if not digit then return 1)
        for (int i = 0, argvlength = strlen(argv[1]); i < argvlength; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

    //otherwise prompts user for a word to be cyphered and stores as variable c.
    {
        c = get_string("plaintext:  ");
    }

    //number inputted at command line is taken as a string by argv so converted to integer here.
    int k = atoi(argv[1]);


    //create loop that cyphers each letter in the string (strings are an array as standard in C)

    //creat variable "length" to measure and store the length of the input word. This can then be used as the value to terminate the main loop.
    int length = strlen(c);

    printf("ciphertext: ");

    for (int i = 0; i < length; i++)

        //check whether first letter is a character or letter. The "!"" means if "is not" an aphabetic letter.
        //if not an alphabetic letter then just print the character as it is with no conversion.
    {
        if (!isalpha(c[i]))
        {
            printf("%c", c[i]);
        }
        //check if letter is uppercase - if it is the minus 65
        else if (isupper(c[i]))

        {
            //if so then minus 65 to get alphabetic index (0-25) and store a character variable "u". This step may be extra work.
            char u = (c[i] - 65);
            //perform Caesar formula to get cyphertext.
            char cypherupper = ((u + k) % 26);
            //add 65 to return character to ASCII and print chracter
            printf("%c", cypherupper + 65);
        }
        //otherwise the character must be a lowercase letter so perform similar task to above to get alphabetic index.
        else
        {
            char l = (c[i] - 97);
            char cypherlower = ((l + k) % 26);
            printf("%c", cypherlower + 97);
        }
    }
    //print on to next line as per spec.
    printf("\n");
    //return zero to apparently exit as per spec.
    return 0;
}