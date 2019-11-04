/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:40:43 by mravily           #+#    #+#             */
/*   Updated: 2019/09/15 00:23:52 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_loop_incr(int nombre1, int nombre2, int nombre3)
{
	while (nombre3 <= 9)
	{
		ft_putchar(nombre1 + 48);
		ft_putchar(nombre2 + 48);
		ft_putchar(nombre3 + 48);
		if (nombre3 <= 9)
			nombre3++;
		if (nombre3 >= 10)
		{
			nombre2++;
			nombre3 = nombre2 + 1;
		}
		if (nombre2 >= 9)
		{
			nombre1++;
			nombre2 = nombre1 + 1;
			nombre3 = nombre2 + 1;
		}
		if (nombre1 <= 7)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb(void)
{
	int nombre1;
	int nombre2;
	int nombre3;

	nombre1 = 0;
	nombre2 = 1;
	nombre3 = 2;
	ft_loop_incr(nombre1, nombre2, nombre3);
}
