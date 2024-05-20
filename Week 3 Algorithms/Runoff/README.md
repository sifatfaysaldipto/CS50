# Code Explanation

## Purpose
The purpose of this code is to implement a runoff voting system where voters rank the candidates in order of preference. The program takes command-line arguments as the names of the candidates, then prompts the user to input their preferences. It then calculates the winner of the election based on the preferences and conducts multiple rounds of runoff voting if necessary.

## Libraries
- `cs50.h`: This library provides functions for getting user input, such as `get_int` and `get_string`.
- `stdio.h`: This library provides standard input and output functions, such as `printf`.
- `string.h`: This library provides string manipulation functions, such as `strcmp`.

## Constants
- `MAX_VOTERS`: Represents the maximum number of voters allowed.
- `MAX_CANDIDATES`: Represents the maximum number of candidates allowed.

## Global Variables
- `preferences[MAX_VOTERS][MAX_CANDIDATES]`: 2D array storing the preferences of each voter for each candidate.
- `candidate`: Struct representing a candidate, containing their name, number of votes, and elimination status.
- `candidates[MAX_CANDIDATES]`: Array of candidate structures.
- `voter_count`: Number of voters.
- `candidate_count`: Number of candidates.

## Function Prototypes
- `bool vote(int voter, int rank, string name)`: Records the preference if the vote is valid.
- `void tabulate(void)`: Tabulates votes for non-eliminated candidates.
- `bool print_winner(void)`: Prints the winner of the election if there is one.
- `int find_min(void)`: Returns the minimum number of votes any remaining candidate has.
- `bool is_tie(int min)`: Returns true if the election is tied between all candidates, false otherwise.
- `void eliminate(int min)`: Eliminates the candidate (or candidates) in last place.

## Function: main()
- `int main(int argc, string argv[])`: This is the main function where the execution of the program begins. It takes command-line arguments `argc` (argument count) and `argv` (argument vector) as parameters and returns an integer value.
    - Validates the command-line arguments and populates the array of candidates.
    - Prompts the user to input the number of voters and their preferences.
    - Conducts runoff voting rounds until a winner is determined or a tie occurs.

## Other Functions
- `vote(int voter, int rank, string name)`: Records the preference of a voter if the vote is valid by updating the preferences array.
- `tabulate()`: Updates the vote counts for non-eliminated candidates based on voter preferences.
- `print_winner()`: Determines if there is a winner of the election based on the majority of votes and prints their name if there is one.
- `find_min()`: Finds the minimum number of votes any remaining candidate has.
- `is_tie(int min)`: Checks if the election is tied between all candidates based on the minimum number of votes and returns true if it is.
- `eliminate(int min)`: Eliminates the candidate (or candidates) in last place by marking them as eliminated.

## Note
- This code assumes that the input preferences are valid and that there is at least one voter and one candidate.
- In case of a tie, the program prints the names of all candidates with the highest number of votes.
- The runoff voting process continues until a winner is determined or a tie occurs.