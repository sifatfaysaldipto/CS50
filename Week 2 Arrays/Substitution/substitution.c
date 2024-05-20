#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Function prototypes
bool validate_key(string key);
void do_substitute(string key);
char substitute_char(char c, string key);

// Global constant for the alphabet array
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get the key from command-line argument
    string key = argv[1];

    // Validate the key
    if (!validate_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Perform substitution
    do_substitute(key);

    return 0;
}

// Function to validate the substitution key
bool validate_key(string key)
{
    // Key must be exactly 26 characters long
    if (strlen(key) != 26)
    {
        return false;
    }

    // Array to keep track of seen characters in the key
    bool seen[26] = {false};

    // Iterate through each character in the key
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        // Check if the character is alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Convert character to uppercase and calculate index in alphabet
        int index = toupper(key[i]) - 'A';

        // Check if the character is repeated
        if (seen[index])
        {
            return false;
        }

        // Mark the character as seen
        seen[index] = true;
    }

    return true;
}

// Function to perform substitution on plaintext
void do_substitute(string key)
{
    // Get plaintext input from user
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Iterate through each character in plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if character is alphabetic
        if (isalpha(plaintext[i]))
        {
            // Substitute the character and print
            printf("%c", substitute_char(plaintext[i], key));
        }
        else
        {
            // Print non-alphabetic characters as they are
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}

// Function to substitute a single character based on the key
char substitute_char(char c, string key)
{
    // Convert character to uppercase
    char uppercase_c = toupper(c);

    // Calculate index of character in alphabet
    int index = uppercase_c - 'A';

    // Get substituted character from key
    char substitute = key[index];

    // Return substituted character with original case
    if (islower(c))
    {
        return tolower(substitute);
    }
    else
    {
        return substitute;
    }
}