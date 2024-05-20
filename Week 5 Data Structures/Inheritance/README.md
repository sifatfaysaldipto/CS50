# Code Explanation

## Purpose
This program generates a family tree representing blood type inheritance across multiple generations. It creates a hierarchical structure of individuals, each with two parents and two alleles representing blood type.

## Functions

### `main()`
- The entry point of the program.
- Seeds the random number generator.
- Creates a family with a specified number of generations.
- Prints the family tree of blood types.
- Frees memory allocated for the family tree.

### `create_family(int generations)`
- Creates a new individual with a specified number of generations.
- Allocates memory for a new person.
- Recursively creates parents for each person based on the number of generations.
- Randomly assigns alleles to individuals based on their parents' alleles.
- Returns a pointer to the newly created person.

### `free_family(person *p)`
- Frees memory allocated for the family tree recursively.
- Handles the base case where the pointer is NULL.
- Calls itself recursively to free memory for parents.
- Frees memory for the current person.

### `print_family(person *p, int generation)`
- Prints each family member and their alleles recursively.
- Handles the base case where the pointer is NULL.
- Prints indentation based on the generation.
- Prints the person's details, including their blood type alleles.
- Recursively prints the parents of each person.

### `random_allele()`
- Randomly chooses a blood type allele ('A', 'B', or 'O') for an individual.

## Variables and Constants
- `GENERATIONS`: Constant integer representing the number of generations in the family tree.
- `INDENT_LENGTH`: Constant integer representing the length of indentation for each generation in the family tree.

## Note
- This program uses recursion to generate and print the family tree.
- It randomly assigns blood type alleles to each individual based on the alleles of their parents.
- Blood type alleles are represented by characters 'A', 'B', and 'O'.