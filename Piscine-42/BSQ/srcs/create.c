/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:38:48 by adbenoit          #+#    #+#             */
/*   Updated: 2019/09/18 23:43:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		*ft_malloc(char **lines, int **num)
{
	int i;
	int j;

	i = 0;
	while (lines[i])
		i++;
	if (!(num = malloc(sizeof(int) * i)))
		return (0);
	i = -1;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j])
			j++;
		if (!(num[i] = malloc(sizeof(int) * j)))
			return (0);
	}
	return (num);
}

int		**create(char **lines)
{
	int			i;
	int			j;
	int			**num;

	i = -1;
	num = NULL;
	num = ft_malloc(lines, num);
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'o')
				num[i][j] = 0;
			else
				num[i][j] = j + 1;
			j++;
		}
	}
	return (num);
}
