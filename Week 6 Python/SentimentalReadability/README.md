# Code Explanation

## Purpose
This Python script analyzes the readability of text using the Coleman-Liau index, which approximates the U.S. grade level needed to comprehend the text.

## Program Description
- The script prompts the user to enter a text.
- It calculates the number of letters, words, and sentences in the text.
- Based on these metrics, it calculates the average number of letters per 100 words and the average number of sentences per 100 words.
- Using the Coleman-Liau index formula, it computes the approximate grade level needed to comprehend the text.
- Finally, it prints the grade level rounded to the nearest whole number.

## Functions and Logic
- The `main()` function is the entry point of the program. It prompts the user for input and calculates the readability index.
- `count_letters(sentence)`: Counts the number of letters in the text by iterating over each character and checking if it's alphabetic.
- `count_words(sentence)`: Counts the number of words by splitting the input string based on whitespace and returning the length of the resulting list.
- `count_sentences(sentence)`: Counts the number of sentences by iterating over each character and incrementing the count when encountering sentence-ending punctuation marks (., !, ?).
- `calculate_index(avg_letters, avg_sentences)`: Computes the Coleman-Liau index using the formula: 0.0588 * L - 0.296 * S - 15.8, where L is the average number of letters per 100 words and S is the average number of sentences per 100 words.
- The script then prints the grade level based on the computed index, with adjustments for extreme values (less than Grade 1 or 16 or more).

## Note
- The script assumes that the input text contains valid English sentences.
- It utilizes string manipulation and basic arithmetic operations to analyze the text.