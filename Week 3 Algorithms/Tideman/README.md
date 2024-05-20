# Code Explanation

## Purpose
The purpose of this code is to implement the Tideman voting method, which is a ranked-choice voting system. The program allows voters to rank candidates in order of preference. It then calculates the winner of the election based on these preferences while avoiding cycles in the preference graph.

## Libraries
- `cs50.h`: This library provides functions for getting user input, such as `get_int` and `get_string`.
- `stdio.h`: This library provides standard input and output functions, such as `printf`.
- `stdlib.h`: This library provides functions such as `qsort` for sorting elements.
- `string.h`: This library provides string manipulation functions, such as `strcmp`.

## Constants
- `MAX`: Represents the maximum number of candidates.

## Global Variables
- `preferences[MAX][MAX]`: 2D array storing the number of voters who prefer one candidate over another.
- `locked[MAX][MAX]`: 2D array indicating whether a candidate is locked in over another in the preference graph.
- `candidates[MAX]`: Array of candidate names.
- `pairs[MAX * (MAX - 1) / 2]`: Array of pairs of candidates, each with a winner and a loser.
- `pair_count`: Number of pairs.
- `candidate_count`: Number of candidates.

## Function Prototypes
- `bool vote(int rank, string name, int ranks[])`: Updates ranks given a new vote.
- `void record_preferences(int ranks[])`: Updates preferences given one voter's ranks.
- `void add_pairs(void)`: Records pairs of candidates where one is preferred over the other.
- `int comparator(const void *a, const void *b)`: Comparator function used for sorting pairs.
- `void sort_pairs(void)`: Sorts pairs in decreasing order by strength of victory.
- `bool has_cycle(int winner, int loser)`: Checks if adding a pair would create a cycle in the preference graph.
- `void lock_pairs(void)`: Locks pairs into the candidate graph in order, without creating cycles.
- `void print_winner(void)`: Prints the winner of the election.

## Function: main()
- `int main(int argc, string argv[])`: This is the main function where the execution of the program begins. It takes command-line arguments `argc` (argument count) and `argv` (argument vector) as parameters and returns an integer value.
    - Validates the command-line arguments and populates the array of candidates.
    - Prompts the user to input the number of voters and their preferences.
    - Calculates the winner of the election using the Tideman method.

## Other Functions
- `record_preferences(int ranks[])`: Updates the preferences array based on the ranks provided by each voter.
- `add_pairs()`: Records pairs of candidates where one is preferred over the other based on the preferences.
- `sort_pairs()`: Sorts the pairs in decreasing order by the strength of victory.
- `has_cycle(int winner, int loser)`: Checks if adding a pair would create a cycle in the preference graph.
- `lock_pairs()`: Locks pairs into the candidate graph in order, without creating cycles.
- `print_winner()`: Prints the winner of the election based on the candidate graph.

## Note
- The Tideman method avoids cycles in the preference graph to ensure a fair election outcome.
- The program calculates the winner based on the strength of victory in pairwise comparisons.
- It handles tie-breaking by using the candidate who is not locked in over any other candidate as the winner.