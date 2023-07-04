#include <stdio.h>
#include "cs50.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//prototype of shift function (see bottom of program)
int shift(char c);
//takes input from command line eg ""./caesar 13"
int main(int argc, string argv[])
{
    //checks that there is only one input after ./caesar also checks that there is atleast one input after ./caesar
    // note that running the program - "./caesar" counts as one argc
    if (argc > 2 || argc == 1)

        //if more than one input after ./caesar or no inputs then give error message
    {
        printf("Usage: ./vigenere keyword");
        //return 1 to exit.
        return 1;
    }
    else
        //iterate through the key to check that the letters are digits (if not digit then return 1)
        for (int i = 0, argvlength = strlen(argv[1]); i < argvlength; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword");
                return 1;
            }
        }
    //otherwise prompts user for a word to be cyphered and stores as variable c.
    string c = get_string("plaintext:  ");
    
    
    printf("ciphertext: ");
    //create loop that cyphers each letter in the string (strings are an array as standard in C)
    //j is a seperate counter that iterates through the key. j only increases by one if the character in the plaintext word is a letter and does not increase if the character is a symbol.
    int j = 0;
    //create variable called length within for loop parameters to store the length of the plaintext word. This can then be used as value to terminate main loop.
    for (int i = 0, length = strlen(c); i < length; i++)

    {
        int length1 = strlen(argv[1]);
        //variable k becomes the holder for each character iteration of the keyword after the "shift" function has been applied to it. So k becomes the alphabetic index of the letter in the keyword.
        //using j%length1 means that when all the letters in the keyword have been used it loops back to the start of the keyword. Whereas in 
        int k = shift(argv[1][j % length1]);
        
        if (!isalpha(c[i]))
        {
            printf("%c", c[i]);
        }
        //check if letter is uppercase - if it is then use shift function to get alphabetic index number.
        else if (isupper(c[i]))
        {
            //perform Caesar formula to get cyphertext.
            char cipherupper = ((shift(c[i]) + k) % 26);
            //add 65 to return character to ASCII and print chracter
            printf("%c", cipherupper + 65);
            //add 1 to j so that on next loop we use the next character in the key
            j++;
        }
        //otherwise the character must be a lowercase letter so perform similar task to above to get alphabetic index.
        else
        {
            char cipherlower = ((shift(c[i]) + k) % 26);
            printf("%c", cipherlower + 97);
            j++;
        }
    }
    //print on to next line as per spec.
    printf("\n");
    //return zero to apparently exit as per spec.
    return 0;
}
//function to shift ascii character to alphabetic index
int shift(char c)
{
    if (isupper(c))
    {
        return c - 65;
    }
    else
    {
        return c - 97;
    }
}
