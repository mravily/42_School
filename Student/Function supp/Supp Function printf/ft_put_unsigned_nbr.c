/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 00:56:44 by mravily           #+#    #+#             */
/*   Updated: 2019/12/04 01:00:01 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr(int nbr, t_tool_box *t_box)
{
	unsigned int	i;

	i = nbr;
	if (i > 9)
	{
		ft_put_unsigned_nbr(i / 10, t_box);
		ft_put_unsigned_nbr(i % 10, t_box);
	}
	else
		ft_putchar(i + 48, t_box);
}
