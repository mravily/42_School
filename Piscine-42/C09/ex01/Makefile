# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 16:54:25 by mravily           #+#    #+#              #
#    Updated: 2019/09/18 18:51:37 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs/

HEAD_DIR = ./includes/

NAME = libft.a

SRC = ${SRC_DIR}ft_putchar.c\
      ${SRC_DIR}ft_swap.c\
      ${SRC_DIR}ft_putstr.c\
      ${SRC_DIR}ft_strlen.c\
      ${SRC_DIR}ft_strcmp.c\

HEAD = ${HEAD_DIR}ft.h

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}	
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
		
.c.o:
	${CC} ${CFLAGS} -c $< -I${HEAD_DIR} -o ${<:.c=.o}

clean:
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
				
re: 	fclean all

.PHONY:	all clean fclean re 
		
		