#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner or if it's a tie
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!");
    }
}

// Function to compute the score of a word
int compute_score(string word)
{
    // Initialize score
    int score = 0;

    // Compute and return score for the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Check if the character is uppercase
        if (isupper(word[i]))
        {
            // Calculate score based on uppercase letter
            score += POINTS[word[i] - 'A'];
        }
            // Check if the character is lowercase
        else if (islower(word[i]))
        {
            // Calculate score based on lowercase letter
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}