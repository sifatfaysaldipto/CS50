# Code Explanation

## Purpose
This program calculates the minimum number of coins (quarters, dimes, nickels, and pennies) required to give back change for a given amount of cents.

## Functions

### `main()`
- The main function of the program.
- Prompts the user for the number of cents and then calculates the minimum number of coins needed to make that amount of change.
- It utilizes helper functions to calculate the number of each type of coin.
- Finally, it prints the total number of coins required to give back the change.

### `get_cents()`
- Prompts the user for the number of cents, ensuring it's non-negative.
- Returns the number of cents entered by the user.

### `calculate_quarters()`, `calculate_dimes()`, `calculate_nickels()`, `calculate_pennies()`
- These functions calculate the number of quarters, dimes, nickels, and pennies respectively, based on the remaining cents after calculating the previous denominations.
- They take the remaining number of cents as input and return the number of respective coins needed.

## Note
- This program assumes that the CS50 library is properly installed and configured in the environment.