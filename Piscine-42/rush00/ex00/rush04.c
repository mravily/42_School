/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:59:56 by mravily           #+#    #+#             */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_line_up(int xmax, int xmin)
{
	ft_putchar('A');
	while (xmin < xmax)
	{
		if (xmin < xmax - 1)
			ft_putchar('B');
		if (xmin == xmax - 1)
			ft_putchar('C');
		xmin++;
	}
	ft_putchar('\n');
}

void	ft_line_center(int ymin, int xmax1, int ymax, int compt)
{
	while (compt < ymax - 2)
	{
		ft_putchar('B');
		while (ymin < xmax1 - 2)
		{
			ft_putchar(' ');
			ymin++;
		}
		if (xmax1 != 1)
			ft_putchar('B');
		ft_putchar('\n');
		ymin = 0;
		compt++;
	}
}

void	ft_line_down(int xmin, int xmax2, int ymin3)
{
	if (ymin3 > 1)
	{
		if (xmin <= xmax2 + 2)
		{
			ft_putchar('C');
		}
		while (xmin < xmax2)
		{
			if (xmin < xmax2 - 1)
				ft_putchar('B');
			if (xmin == xmax2 - 1)
				ft_putchar('A');
			xmin++;
		}
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	ft_line_up(x, 1);
	ft_line_center(0, x, y, 0);
	ft_line_down(1, x, y);
	ft_putchar('\n');
}
