#!/bin/bash

# ---------------------------------------------
gcc -fsanitize=address -o test main.c ft_printf.c source/*.c libft/libft.a
./test
# ---------------------------------------------
