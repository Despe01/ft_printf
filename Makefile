# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smurad <smurad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:59:58 by smurad            #+#    #+#              #
#    Updated: 2019/12/18 19:06:37 by smurad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

SRCS    =   ft_printf.c $(wildcard source/*.c)


OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		cp libft/libft.a ./$(NAME)
		ar rcs $(NAME) $(OBJS)

clean:
		make -C $(LIBFT) fclean
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean	all

.PHONY: clean fclean all
