# Simple_shell

In this repository (Project), I am working on a custom shell which mimick how the shell work.  
Originally created for learning purposes in the ALX SE programme - Cohort 16.

## Compilation and Memory leak checks
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsanitize=address -g *.c -o ./hsh`

`valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck ./hsh`


