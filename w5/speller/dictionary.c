// Implements a dictionary's functionality

#include <cstddef>
#include <cstdio>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 132;

// Hash table
node *table[N];

int words = 0;

node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return NULL;

    if (word != NULL)
        strcpy(new_node->word, word);

    new_node->next = NULL;

    return new_node;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index_hash = hash(word);
    node *current_node = table[index_hash];

    while (current_node != NULL) {
        if (strcasecmp(current_node->word, word)) {
            return true;
        }
        current_node = current_node->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
  int count = 0;
  int limit = 3;

  int word_len = strlen(word);

  if (word_len > limit) word_len = limit;

  for (int i = 0; i < word_len; i++) {
    char chr = word[i];
    if (chr == '\'')
      count += 'A' - '\'' + 1;
    else
      count += 1 + toupper(chr) - 'A';
  }

  int rest = (word_len - 1) * 25;

    return count + rest;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if (source == NULL) return false;

    char word[LENGTH + 1];

    while (fgets(word, sizeof(word), source))
    {
        // Remove \n
        word[strcspn(word, "\n")] = '\0';

        // Update counter
        words++;

        // Add word in table hash
        int index_hash = hash(word);
        node *current_node = table[index_hash];

        if (current_node == NULL) {
            node *new_node = create_node(word);
            if (new_node == NULL) {
                fclose(source);
                return false;
            }

            new_node->next = create_node(NULL);
            table[index_hash] = new_node;
            continue;
        }
    }
    
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *current_node;

    for (int i = 0; i < LENGTH; i++) {
        current_node = table[i];

        while (current_node != NULL) {
            free(current_node->word);
            current_node = current_node->next;
        }
    }

    return true;
}
