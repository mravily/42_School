/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:19:07 by mravily           #+#    #+#             */
/*   Updated: 2019/09/08 16:54:31 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	***ft_malloc(char ***table, int side, int size)
{
	int i;
	int j;
	int rows;
	int cols;

	i = 0;
	rows = size;
	cols = size;
	table = malloc(rows * sizeof (char**));
	while (i < rows)
	{
		table[i] = malloc(cols * sizeof (char*));
		j = 0;
		while (j < cols)
		{
			table[i][j] = malloc(side * sizeof (char));
			j++;
		}
		i++;
	}
	return (table);
}
