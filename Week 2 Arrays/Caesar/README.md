# Code Explanation

## Purpose
The purpose of this code is to analyze the readability level of a text input by the user using the Coleman-Liau index. The program calculates the index based on the average number of letters per 100 words and the average number of sentences per 100 words in the text.

## Libraries
- `cs50.h`: This library is specific to the CS50 course and provides additional functions, including `get_string`, which is used to get a string input from the user.
- `stdio.h`: This library provides input and output functions such as `printf`.
- `string.h`: This library provides functions for string manipulation, such as `strlen`.
- `ctype.h`: This library provides functions for character classification and conversion, such as `isalpha`.
- `math.h`: This library provides mathematical functions, such as `round`.

## Function: main()
- `int main(void)`: This is the main function where the execution of the program begins. It returns an integer value.
    - `string text = get_string("Text: ");`: This line prompts the user to enter a text input and stores it in the variable `text`, which is of type `string`.
    - Calculates the number of letters, words, and sentences in the input text using the `count_letters`, `count_words`, and `count_sentences` functions respectively.
    - Calculates the average number of letters per 100 words (`avgLetters`) and the average number of sentences per 100 words (`avgSentences`).
    - Calculates the Coleman-Liau index using the formula `0.0588 * avgLetters - 0.296 * avgSentences - 15.8` and rounds the result.
    - Prints out the readability level based on the calculated index.

## Function: count_letters()
- `int count_letters(string text)`: This function takes a string `text` as input and returns the number of letters (alphabetical characters) in the text.
    - Initializes a variable `letters` to 0.
    - Iterates through each character in the text using a for loop and increments `letters` when an alphabetical character is encountered.
    - Returns the total number of letters.

## Function: count_words()
- `int count_words(string text)`: This function takes a string `text` as input and returns the number of words in the text.
    - Initializes a variable `words` to 1 (assuming at least one word).
    - Iterates through each character in the text using a for loop and increments `words` when a space character is encountered.
    - Returns the total number of words.

## Function: count_sentences()
- `int count_sentences(string text)`: This function takes a string `text` as input and returns the number of sentences in the text.
    - Initializes a variable `sentences` to 0.
    - Iterates through each character in the text using a for loop and increments `sentences` when a period ('.'), exclamation mark ('!'), or question mark ('?') is encountered.
    - Returns the total number of sentences.

## Note
- This code assumes that the CS50 library is properly installed and configured in the environment.
- It expects the user to input a text string for analysis.
