#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    string text = get_string("Text: ");

    double letters = 0;
    double words = 0;
    double sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        char previousLetter = text[i - 1];

        // --- COUNT LETTERS ---
        if (isalpha(letter))
        {
            letters++;
        }

        // --- COUNT WORDS ---
        if (letter == 32)
        {
            words++;
        }
        if (i == strlen(text) - 1)
        {
            words++;
        }

        // --- COUNT SENTENCES ---
        if (letter == 63 || letter == 33 || letter == 46)
        {
            sentences++;
        }
    }

    double L = (letters / words) * 100;
    double S = (sentences / words) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)(round(index)));
    }

}