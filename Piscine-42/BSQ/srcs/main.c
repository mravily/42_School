/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:05:22 by adbenoit          #+#    #+#             */
/*   Updated: 2019/09/18 23:44:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_change(char **lines, t_air *tab)
{
	int i;
	int y;
	int x;
	int obs;
	int size;

	size = (ft_size2(lines) - 2) * ft_strlen(lines[1]);
	obs = 0;
	while (lines[0][obs] >= '0' && lines[0][obs] <= '9')
		obs++;
	obs++;
	i = tab[size - 2].max;
	x = tab[i].x;
	while (x < tab[i].c + tab[i].x)
	{
		y = tab[i].y;
		while (y < tab[i].c + tab[i].y)
		{
			lines[x][y] = lines[0][obs + 1];
			y++;
		}
		x++;
	}
	free(tab);
	return (lines);
}

void	ft_display(char **lines)
{
	int i;

	i = 1;
	while (lines[i])
	{
		ft_putstr(lines[i]);
		ft_putchar('\n');
		i++;
	}
}


int		main(int ac, char **av)
{
	char	**lines;
	char	*len;
	t_air	*tab;
<<<<<<< HEAD:srcs/main.c

	(void)ac;
	len = stread(av[1]);
	lines = ft_mapparser(len);
	tab = ft_square(lines);
	lines = ft_change(lines, tab);
	ft_display(lines);
	return (0);
=======
	int		i;

	i = 1;
	while (av[i])
	{
		len = stread(av[i]);
		lines = ft_mapparser(len);
		if (error(lines, ac) == 0)
		{
			write(1, "map error\n", 10);
			i++;
			if (i < ac)
			{
				free(lines);
				len = stread(av[i]);
				lines = ft_mapparser(len);
			}
			else
				return (0);
		}	
		tab = ft_square(lines);
		lines = ft_change(lines, tab);
		ft_display(lines);
		free(tab);
		free(lines);
		i++;
	}
	return(0);
>>>>>>> 1a9a129fe6747720031f54e368c0db679f80d429:test1/main.c
}
