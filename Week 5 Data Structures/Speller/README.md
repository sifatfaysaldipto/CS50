# Code Explanation

## Purpose
This program implements a simple spell checker using a hash table data structure to efficiently store and retrieve words from a dictionary file. It provides functions to check if a word is in the dictionary, load the dictionary into memory, return the number of words in the dictionary, and unload the dictionary from memory.

## Included Libraries
- `stdio.h`: Standard Input/Output library for basic input/output operations.
- `stdlib.h`: Standard library providing functions like memory allocation and conversions.
- `string.h`: String manipulation functions.
- `strings.h`: Contains additional string manipulation functions.
- `ctype.h`: Character handling functions.
- `stdbool.h`: Standard library for Boolean types and values.

## Data Structures
- **Node**: Represents a node in the hash table, containing a word and a pointer to the next node.
- **Hash Table**: An array of linked lists (buckets) where words are stored based on their hash values.

## Global Variables
- `N`: Number of buckets in the hash table.
- `counter`: Counter for the number of words in the dictionary.
- `table`: Hash table storing linked lists of nodes.

## Functions

### `check(const char *word)`
- Returns `true` if the word is found in the dictionary, `false` otherwise.
- Uses the hash table to efficiently locate the word.

### `hash(const char *word)`
- Hashes a word to obtain a hash value.
- Uses a custom hashing algorithm based on the sum of the ASCII values of characters in the word.

### `load(const char *dictionary)`
- Loads the dictionary file into memory.
- Reads each word from the dictionary file, creates a node for it, and inserts it into the hash table.
- Returns `true` if successful, `false` otherwise.

### `size()`
- Returns the number of words in the dictionary.
- Utilizes the global `counter` variable to keep track of the word count.

### `unload()`
- Frees memory allocated for the hash table and nodes.
- Iterates through each bucket of the hash table, freeing the memory for the linked list nodes.
- Returns `true` if successful, `false` otherwise.

## Constants
- `LENGTH`: Maximum length for a word in the dictionary.

## Note
- This program uses a simple custom hashing algorithm, which may not be as efficient as other hash functions.
- It assumes that the dictionary file provided adheres to a specific format (words separated by whitespace).
- The hash table size (`N`) can be adjusted for performance optimization.