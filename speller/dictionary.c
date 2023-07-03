// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// number of buckets in hash table
const unsigned int N = 52;

// Hash table
node *table[N];

// variables for counting words and confirming file loaded that are modified from within functions
unsigned int wordsAdded = 0;
bool fileLoaded = false;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // run hash function to find correct bucket
    int index = hash(word);
    node *cursor = table[index];

    // loop over words in linked list (dictionary) and compare to text
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            // move cursor to next node ready for next loop
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // check if word has less than 5 letters
    if (strlen(word) < 5)
    {
        // if so, store in bucket relating to first letter only
        return toupper(word[0]) - 'A';
    }
    else
    {
        // if 5 or more letters then store in bucket in second half of table
        return (toupper(word[0]) - 'A') + 26;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // create a file pointer and read the dictionary file in to it
    FILE *temp;
    temp = fopen(dictionary, "r");
    // if temp is empty then exit function and print error
    if (temp == NULL)
    {
        fprintf(stderr, "Could not load dictionary.\n");
        return false;
    }
    // set file loaded flag to true for unload function to see
    fileLoaded = true;
    // character array created and set to constnt LENGTH + 1 to allow for null termination
    char word[LENGTH + 1];

    // loop over each word in the file
    while (fscanf(temp, "%s", word) != EOF)
    {
        // return a memory address from malloc and assign it to n
        node *n = malloc(sizeof(node));

        // if memory is not available for any reason then exit the function
        if (n == NULL)
        {
            free(n);
            return false;
        }

        // copy the word from the file in to the word variable of node n
        strcpy(n->word, word);
        // set the pointer variable of node n to NULL initially
        n->next = NULL;

        // has the word from file to find correct bucket
        unsigned int index = hash(word);

        // check to see if bucket is empty
        if (table[index] == NULL)
        {
            // if empty then place n in the first slot of the bucket
            table[index] = n;
            wordsAdded++;
        }
        else
        {
            // if a node already exists in bucket then point n's pointer variable to the same address as that of the first node (the second node)
            n->next = table[index]->next;
            // point the first node in the bucket to n node
            table[index]->next = n;
            wordsAdded++;
        }
    }
    fclose(temp);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (fileLoaded)
    {
        return wordsAdded;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // loop through each position of table where N is the number of buckets in table
    for (int i = 0; i < N; i++)
    {
        // declare a pointer and set it to point at the first node in the bucket
        node *pointer = table[i];

        // as long as pointer does not point to NULL (end of linked list) then keep looping
        while (pointer != NULL)
        {
            // create a temp pointer and set it to point at the same address as pointer
            node *tmp = pointer;
            // move pointer to the next node ready for next loop iteration
            pointer = pointer->next;
            // now it is safe to free the node itself without losing the position of pointer
            free(tmp);
        }
    }

    return true;
}