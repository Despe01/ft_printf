#!/bin/bash

# ---------------------------------------------
gcc -Wall -Wextra -Werror -fsanitize=address -o test.out main.c ft_printf.c source/*.c libft/libft.a
./test.out
# ---------------------------------------------
