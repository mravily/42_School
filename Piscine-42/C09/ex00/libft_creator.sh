# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravily <mravily@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 14:26:48 by mravily           #+#    #+#              #
#    Updated: 2019/09/15 15:35:24 by mravily          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

gcc -c ft_swap.c ft_strlen.c ft_strcmp.c ft_putstr.c ft_putchar.c 
ar rc libft.a ft_swap.o ft_strlen.o ft_strcmp.o ft_putstr.o ft_putchar.o