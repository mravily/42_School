/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:56:18 by adbenoit          #+#    #+#             */
/*   Updated: 2019/09/18 23:44:14 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_size2(char **lines)
{
	int size;

	size = 0;
	while (lines[size])
		size++;
	return (size);
}

int		ft_check(char **lines, int x, int y, int c)
{
	int i;
	int j;
	int k;
	int l;
	int obs;

	i = x;
	j = y;
	obs = 0;
	while (lines[0][obs] >= '0' && lines[0][obs] <= '9')
		obs++;
	obs++;
	while (lines[++i][++j] != lines[0][obs] && i < ft_size2(lines) - 1
	&& j < ft_strlen(lines[1]) - 1)
	{
		k = i;
		l = j;
		while (lines[k][y] != lines[0][obs] && k >= x)
			k--;
		while (lines[x][l] != lines[0][obs] && l >= y)
			l--;
		if (l + 1 == y && k + 1 == x)
			c++;
		else
			return (c);
	}
	return (c);
}

int		ft_malloc(t_air **tab, char **lines, int size)
{
	if (!(*tab = malloc(sizeof(t_air) * ((size - 2) * ft_strlen(lines[1])))))
		return (0);
	return (1);
}

t_air	*ft_square(char **lines)
{
	t_air	*tab;
	int		k;
	int		x;
	int		y;
	int		obs;
	int		max;

	obs = 0;
	while (lines[0][obs] >= '0' && lines[0][obs] <= '9')
		obs++;
	obs++;
	ft_malloc(&tab, lines, ft_size2(lines));
	k = 0;
	x = 0;
	while (lines[++x])
	{
		tab[k].x = x;
		y = -1;
		while (lines[x][++y])
		{
			tab[k].y = y;
			if (lines[x][y] != lines[0][obs])
			{
				tab[k].c = 1;
				if (x == ft_size2(lines) - 1 || y == ft_strlen(lines[1]) - 1)
					break ;
				if (lines[x + 1][y] != lines[0][obs] && x != ft_size2(lines) - 1
						&& lines[x][y + 1] != lines[0][obs] &&
						y != ft_strlen(lines[1]) - 1 &&
						lines[x + 1][y + 1] != lines[0][obs])
					tab[k].c = ft_check(lines, x, y, tab[k].c);
			}
			else
				tab[k].c = 0;
			if (k == 0)
				max = k;
			else
			{
				if (tab[k].c > tab[max].c)
					max = k;
				else
					max = tab[max].max;
			}
			tab[k].max = max;
			k++;
		}
		k++;
	}
	return (tab);
}
