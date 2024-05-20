# Code Explanation

## Purpose
This Python script calculates the smallest number of coins needed to give change for a specified amount in dollars.

## Program Description
- The script consists of three functions: `main()`, `get_input()`, and `get_coins(dollars)`.
- The `main()` function is the entry point of the program. It gets the amount in dollars from the user, converts it to cents, calculates the smallest number of coins needed, and prints the result.
- The `get_input()` function prompts the user for a positive float representing the change owed. It converts the input amount to cents (integer) and returns it.
- The `get_coins(dollars)` function calculates the smallest number of coins needed to give change for the specified amount in cents.
- The available coin denominations are 25 cents (quarters), 10 cents (dimes), 5 cents (nickels), and 1 cent (pennies).
- The function iterates through each coin denomination, divides the remaining amount by the coin value, updates the remaining amount, and counts the number of coins used.
- The process continues until the remaining amount becomes zero.

## Code Execution
- The script starts by calling the `main()` function.
- Inside `main()`, it prompts the user for the amount of change owed in dollars and converts it to cents using the `get_input()` function.
- Then, it calculates the smallest number of coins needed using the `get_coins()` function and prints the result.

## Note
- This script assumes that the user will input a positive float representing the change owed.
- It utilizes a while loop in the `get_input()` function to ensure that the user enters a valid positive amount.
- The coin denominations used are standard US denominations: quarters, dimes, nickels, and pennies.
- The script rounds down any fractional cents to the nearest integer value.
