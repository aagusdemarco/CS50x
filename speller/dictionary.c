// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Counter of Words in the file
int word_amount = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Initialize the table and a cursor that points towards each element of the list
    int hash_value = hash(word);
    node *cursor = table[hash_value];

    // Loop through all of the words and check if they exist
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Good enough
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open file and check if it's empty
    FILE *dictf = fopen(dictionary, "r");
    if (dictf == NULL)
    {
        return false;
    }

    // Copy each word from the file to the hash table
    char buffer[45];
    while (fscanf(dictf, "%s", buffer) != EOF)
    {
        node *new_word = malloc(sizeof(node));
        int hash_value = hash(buffer);
        strcpy(new_word->word, buffer);
        new_word->next = table[hash_value];
        table[hash_value] = new_word;
        word_amount++;
    }
    fclose(dictf);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_amount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Loop through the list
    for (int i = 0; i < N; i++)
    {
        // Declare two pointers for each element of the list
        node *tmp = table[i];
        node *cursor = table[i];

        // Loop through, freeing the element and following to the next word
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
