# Code Explanation

## Purpose
This Python script validates credit card numbers using the Luhn's algorithm and identifies the card issuer (VISA, MASTERCARD, or AMEX).

## Program Description
- The script reads a credit card number from the user and performs the Luhn's algorithm to validate it.
- It then checks the length and starting digits of the credit card number to determine the card issuer.
- Finally, it prints the result indicating whether the credit card number is valid and the issuer if applicable.

## Functions and Logic
- The `main()` function is the entry point of the program. It reads a credit card number from the user and performs the validation process.
- Inside the main loop, the script iterates through each digit of the credit card number.
- For every even-indexed digit, it adds the digit to the `sum_of_evens`.
- For every odd-indexed digit, it doubles the digit, adds the digits of the result (if greater than 9) to `sum_of_double_odds`.
- After processing each digit, the script checks if the sum of `sum_of_evens` and `sum_of_double_odds` modulo 10 equals 0, indicating a valid credit card number.
- Based on the number of digits and the starting digits, the script identifies the card issuer (VISA, MASTERCARD, or AMEX).
- Finally, it prints the result indicating the card issuer or "INVALID" if the card number is invalid.

## Note
- The script utilizes the `get_int()` function from the CS50 library to get user input.
- It implements the Luhn's algorithm to validate credit card numbers, which involves summing the digits of the card number according to certain rules.
- The script then checks the length and starting digits to identify the issuer.
- It assumes that the user inputs a valid numeric credit card number.
