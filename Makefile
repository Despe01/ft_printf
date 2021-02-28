# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smurad <smurad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 17:59:58 by smurad            #+#    #+#              #
#    Updated: 2021/02/28 22:02:14 by smurad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

SRCS    =   ft_printf.c \
				source/ft_append_char.c \
				source/ft_ctype.c \
				source/ft_dtype.c \
				source/ft_flag_identifier.c \
				source/ft_itoa_base.c \
				source/ft_join.c \
				source/ft_joinprec.c \
				source/ft_parse.c \
				source/ft_ptype.c \
				source/ft_stype.c \
				source/ft_typeidentifier.c \
				source/ft_uppercase_xtype.c \
				source/ft_utype.c \
				source/ft_xtype.c


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
