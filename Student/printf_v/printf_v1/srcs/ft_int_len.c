/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:33:54 by mravily           #+#    #+#             */
/*   Updated: 2019/12/13 15:42:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		ft_int_len(int nb)
{
	//PRINTPOS;
	size_t		int_len;

	int_len = 0;
	while (nb > 0)
	{
		int_len++;
		nb /= 10;
	}
	return (int_len);
}
