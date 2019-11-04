/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_puzzle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:33:39 by richard           #+#    #+#             */
/*   Updated: 2019/09/08 22:04:09 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_countnbr(char *str);

char ***ft_prepare_table(int side, char *str);

void ft_easy_guess(char ***table, int side, int size);

void ft_hard_guess(char ***table, int side, int size);

void ft_print_table(char ***table, int side, int size);

void	ft_solve_puzzle(char *str)
{
	int numbers;
	int side;
	char ***table;

	numbers = ft_countnbr(str);
	if (numbers % 4 == 0)
	{
		side = numbers / 4;
		table = ft_prepare_table(side, str);
		ft_easy_guess(table, side, side + 2);
		ft_hard_guess(table, side, side + 2);
		ft_print_table(table, side, side + 2);
	}
}

void	ft_print_table(char ***table, int side, int size)
{
	int i;
	int j;
	int k;
	int space;
	int newline;

	i = 1;
	side = 0;
	space = 32;
	newline = 10;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			k = 0;
			while (k < size)
			{
				if (table[i][j][k] != '.')
					write(1, &table[i][j][k], 1);
				k++;
			}
			write(1, &space, 1);
			j++;
		}
		write(1, &newline, 1);
		i++;
	}
}
