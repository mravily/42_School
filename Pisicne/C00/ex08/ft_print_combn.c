/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:24:11 by mravily           #+#    #+#             */
/*   Updated: 2019/09/27 13:24:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

unsigned int		ft_combn(int n)
{
	if (n == 1)
		return (9);
	if (n == 2)
		return (99);
	if (n == 3)
		return (999);
	if (n == 4)
		return (9999);
	if (n == 5)
		return (99999);
	if (n == 6)
		return (999999);
	if (n == 7)
		return (9999999);
	if (n == 8)
		return (99999999);
	if (n == 9)
		return (999999999);
	else
		return (0);
}

void	ft_print_combn(int n)
{
	int nbr;
	int valmax;

	valmax = ft_combn(n);
	nbr = 0;
	if (n <= 0 || n > 10)
		return ;
	while (nbr <= valmax)
	{
		ft_putnbr(nbr);
		if (!(nbr == valmax))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		nbr++;
	}

}

int		main(void)
{
	ft_print_combn(2);
}