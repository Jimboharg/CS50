#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins !\n");
    }
    if (score2 > score1)
    {
        printf("Player 2 wins !\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// loop through the word variable and assess each letter, convert to it's alphabetic positions and track the score for each letter
int compute_score(string word)
{
    int scoreCounter = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            // if letter is uppercase then convert it's ASCII to 0-25 (26 letters of alphabet)
            int position = word[i] - 65;
            // find the position of that 0-25 value in the POINTS array and add that value to the core counter variable
            scoreCounter = scoreCounter + POINTS[position];
        }

        if (islower(word[i]))
        {
            // if letter is lowercase then convert it's ASCII to 0-25 (26 letters of alphabet)
            int position = word[i] - 97;
            // find the position of that 0-25 value in the POINTS array and add that value to the core counter variable
            scoreCounter = scoreCounter + POINTS[position];
        }
        // if the letter is neithe rupper or lower case then assume it is not a letter and start loop again without adjusting the score counter
        else
        {
            continue;
        }
    }

    return scoreCounter;

}
