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

SRCS    =   source/ft_append_char.c source/ft_ctype.c \
						source/ft_dtype.c source/ft_flag_identifier.c \
						source/ft_itoa_base.c source/ft_join.c source/ft_parse.c \
						source/ft_ptype.c source/ft_stype.c source/ft_typeidentifier.c \
						source/ft_uppercase_xtype.c source/ft_utype.c source/ft_xtype.c \
						ft_printf.c \
						libft/ft_atoi.c \
						            libft/ft_bzero.c libft/ft_calloc.c \
						            libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
						            libft/ft_isdigit.c libft/ft_isprint.c \
						            libft/ft_itoa.c \
						            libft/ft_memccpy.c \
						            libft/ft_putchar_fd.c \
						            libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
						            libft/ft_putstr_fd.c libft/ft_split.c \
						            libft/ft_strchr.c \
						            libft/ft_strdup.c \
						            libft/ft_strjoin.c libft/ft_strlcat.c \
						            libft/ft_strlcpy.c libft/ft_strlen.c \
						            libft/ft_strmapi.c \
						            libft/ft_strncmp.c libft/ft_strnstr.c \
						            libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
						            libft/ft_tolower.c libft/ft_toupper.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean	all

.PHONY: clean fclean all
