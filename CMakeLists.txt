cmake_minimum_required(VERSION 3.28)
project(CS50 C)

set(CMAKE_C_STANDARD 11)

add_executable(CS50
        "Week 1 C/Hello/hello.c"
        "Week 1 C/Cash/cash.c"
        "Week 1 C/Credit/credit.c"
        "Week 1 C/MarioLess/marioless.c"
        "Week 1 C/MarioMore/mariomore.c"
        "Week 2 Arrays/Scrabble/scrabble.c"
        "Week 2 Arrays/Readability/readability.c"
        "Week 2 Arrays/Caesar/caesar.c"
        "Week 2 Arrays/Substitution/substitution.c"
        "Week 3 Algorithms/Plurality/plurality.c"
        "Week 3 Algorithms/Runoff/runoff.c"
        "Week 3 Algorithms/Tideman/tideman.c"
        "Week 4 Memory/Volume/volume.c"
        "Week 4 Memory/FilterLess/filterless.c"
        "Week 4 Memory/FilterMore/filtermore.c"
        "Week 4 Memory/Recover/recover.c"
        "Week 5 Data Structures/Inheritance/inheritance.c"
        "Week 5 Data Structures/Speller/speller.c")
