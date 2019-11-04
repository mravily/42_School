# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 11:06:21 by mravily           #+#    #+#              #
#    Updated: 2019/09/18 23:31:26 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs/

HEAD_DIR = ./includes/

NAME = BSQ

SRC = ${SRC_DIR}ft_putchar.c\
      ${SRC_DIR}ft_strlen.c\
      ${SRC_DIR}ft_putstr.c\
      ${SRC_DIR}ft_split.c\
      ${SRC_DIR}ft_mapparser.c\
	  ${SRC_DIR}check.c\
	  ${SRC_DIR}create.c\
	  ${SRC_DIR}error.c\
	  ${SRC_DIR}square.c\
	  ${SRC_DIR}main.c\

HEAD = ${HEAD_DIR}BSQ.h

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}	
	$(CC) ${NAME} ${OBJS}
		
.c.o:
	${CC} ${CFLAGS} -c $< -I${HEAD_DIR} -o ${<:.c=.o}

clean:
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
				
re: 	fclean all

.PHONY:	all clean fclean re
		
		
