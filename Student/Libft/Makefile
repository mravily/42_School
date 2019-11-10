# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 08:52:52 by mravily           #+#    #+#              #
#    Updated: 2019/11/07 14:55:41 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c  ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_atoi.c ft_itoa.c\
ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_putchar_fd.c ft_putstr_fd.c ft_strcpy.c ft_putstr_fd.c ft_putenddl_fd.c\

OBJ = $(SRC:.c=.o)

INCLUDE = ./libft.h

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

.o: .c
		$(CC) -I $(INCLUDE) -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean