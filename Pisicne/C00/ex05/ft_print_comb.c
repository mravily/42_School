/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:13:54 by mravily            #+#    #+#             */
/*   Updated: 2019/09/26 22:13:54 by mravily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);

}

void	ft_print_nbr(int nbr1, int nbr2, int nbr3)
{
	ft_putchar(nbr1);
	ft_putchar(nbr2);
	ft_putchar(nbr3);
}

void	ft_print_comb(void)
{
	int nbr1;
	int nbr2;
	int nbr3;

	nbr1 = '0';
	while (nbr1 <= '9')
	{
		nbr2 = nbr1 + 1;
		while (nbr2 <= '9')
		{
			nbr3 = nbr2 + 1;
			while (nbr3 <= '9')
			{
				ft_print_nbr(nbr1, nbr2, nbr3);
				if (!(nbr1 == '7' && nbr2 == '8' && nbr3 == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				nbr3++;
			}
			nbr2++;
		}
		nbr1++;
	}
}
