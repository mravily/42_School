# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 08:52:52 by mravily           #+#    #+#              #
#    Updated: 2019/11/13 19:41:39 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c  ft_memchr.c ft_memmove.c \
		ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_atoi.c ft_itoa.c \
		ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_strcpy.c ft_putstr_fd.c ft_putendl_fd.c ft_strncmp.c \
		ft_split.c ft_putnbr_fd.c ft_strmapi.c ft_strlcpy.c \
		
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): libft.h $(SRC) $(OBJ)
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		
bonus : $(NAME) $(OBJ_BONUS) $(SRC_BONUS)
		$(CC) $(CFLAGS) -c $(SRC_BONUS)
		ar rc $(NAME) $(OBJ_BONUS)
		ranlib $(NAME)
	
all: 	$(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean	
		$(RM) $(NAME)
		
re: fclean all
		
.PHONY: clean fclean