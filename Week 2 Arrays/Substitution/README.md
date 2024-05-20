# Code Explanation

## Purpose
The purpose of this code is to perform a substitution cipher on a given plaintext using a provided key. The program takes a command-line argument as the key and prompts the user for plaintext input. It then substitutes each letter in the plaintext according to the given key, maintaining the case of the letters, and prints the resulting ciphertext.

## Libraries
- `stdio.h`: This library provides input and output functions such as `printf`.
- `cs50.h`: This library is specific to the CS50 course and provides additional functions, including `get_string`, which is used to get a string input from the user.
- `string.h`: This library provides functions for string manipulation, such as `strlen`.
- `ctype.h`: This library provides functions for character classification and conversion, such as `isalpha`, `toupper`, and `tolower`.

## Function: main()
- `int main(int argc, string argv[])`: This is the main function where the execution of the program begins. It takes command-line arguments `argc` (argument count) and `argv` (argument vector) as parameters and returns an integer value.
    - Checks if the number of command-line arguments is 2.
    - Validates the key provided as the command-line argument:
        - Checks if the key contains exactly 26 characters.
        - Checks if the key contains only alphabetic characters and no repeated characters.
    - Calls the `Do_substitute` function if the key is valid.
    - Prints error messages and exits the program if the key is invalid or if the number of command-line arguments is incorrect.

## Function: Do_substitute()
- `void Do_substitute(string key)`: This function performs the substitution cipher on the plaintext using the provided key.
    - Prompts the user for plaintext input.
    - Iterates over each character in the plaintext:
        - Checks if the character is alphabetic.
        - If alphabetic, determines whether it is lowercase or uppercase, then calls the `alpha_arr_val` function to perform the substitution and prints the resulting ciphertext character.
        - If non-alphabetic, prints the character as it is.
    - Prints the resulting ciphertext.

## Function: alpha_arr_val()
- `void alpha_arr_val(char pos, string key)`: This function substitutes an alphabetic character in the plaintext according to the provided key.
    - `pos`: The alphabetic character to be substituted.
    - `key`: The substitution key.
    - Initializes the alphabet array `alpha` containing uppercase letters.
    - Iterates over each letter in the alphabet array:
        - Checks if the position of the plaintext character matches the current letter in the alphabet.
        - If matched, prints the corresponding character from the key while maintaining the case of the plaintext character.

## Note
- This code assumes that the CS50 library is properly installed and configured in the environment.
- The substitution cipher replaces each letter in the plaintext with the corresponding letter from the key, preserving the case of the letters.
- The key must contain exactly 26 unique alphabetic characters.
- The plaintext can contain both alphabetic and non-alphabetic characters, and non-alphabetic characters remain unchanged in the ciphertext.
