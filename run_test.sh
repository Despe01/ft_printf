#!/bin/bash

# ---------------------------------------------
gcc -Wall -Wextra -Werror -fsanitize=address -o test.out main.c libftprintf.a
./test.out
# ---------------------------------------------
