# Code Explanation

## Purpose
The purpose of this code is to implement a plurality voting system, where multiple candidates can receive votes, and the candidate with the most votes wins the election. The program takes candidate names as command-line arguments, accepts votes from users, and determines the winner(s) based on the highest number of votes received.

## Libraries
- `cs50.h`: This library is specific to the CS50 course and provides additional functions, including `get_string` and `get_int`, which are used to get string and integer inputs from the user.
- `stdio.h`: This library provides input and output functions such as `printf`.
- `string.h`: This library provides functions for string manipulation, such as `strcmp`.

## Constants
- `MAX`: This constant defines the maximum number of candidates that the program can handle. It is set to 9 in this code.

## Structure: candidate
- `typedef struct`: This structure represents a candidate in the election.
    - `string name`: This member stores the name of the candidate.
    - `int votes`: This member stores the number of votes received by the candidate.

## Global Variables
- `candidate candidates[MAX]`: This array holds the candidates' information, such as their names and vote counts.
- `int candidate_count`: This variable stores the number of candidates in the election.

## Function: main()
- `int main(int argc, string argv[])`: This is the main function where the execution of the program begins. It takes command-line arguments `argc` (argument count) and `argv` (argument vector) as parameters and returns an integer value.
    - Checks for invalid usage and prints usage instructions if the number of command-line arguments is less than 2.
    - Populates the array of candidates with names provided as command-line arguments.
    - Accepts votes from users and updates the vote totals for each candidate.
    - Calls the `print_winner` function to display the winner(s) of the election.

## Function: vote()
- `bool vote(string name)`: This function updates the vote totals for a candidate given a new vote.
    - Iterates over the candidates' array to find the candidate with the provided name.
    - If the candidate is found, increments the candidate's vote count and returns `true`.
    - If the candidate is not found, returns `false`.

## Function: print_winner()
- `void print_winner(void)`: This function prints the name(s) of the winner(s) of the election.
    - Finds the candidate(s) with the highest number of votes.
    - Prints the name(s) of the candidate(s) with the highest number of votes.

## Note
- This code assumes that the CS50 library is properly installed and configured in the environment.
- Each candidate's name must be provided as a command-line argument.
- After collecting votes, the program determines the winner(s) by finding the candidate(s) with the highest number of votes.
- In case of a tie, all candidates with the highest number of votes are declared winners.