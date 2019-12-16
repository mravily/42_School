/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 01:01:07 by mravily           #+#    #+#             */
/*   Updated: 2019/12/06 20:17:58 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(int nbr, t_tool_box *t_box)
{
	int	i;

	i = nbr;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		t_box->n_char_display += 11;
		return ;
	}
	if (i < 0)
	{
		ft_putchar('-', t_box);
		i = i * (-1);
	}
	if (i > 9)
	{
		ft_putnbr(i / 10, t_box);
		ft_putnbr(i % 10, t_box);
	}
	else
		ft_putchar(i + 48, t_box);
}
