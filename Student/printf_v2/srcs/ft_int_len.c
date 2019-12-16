/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:33:54 by mravily           #+#    #+#             */
/*   Updated: 2019/12/14 20:03:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_int_len(int nb, size_t *i)
{
	size_t		int_len;

	int_len = 0;
	while (nb > 0)
	{
		nb /= 10;
		int_len++;
	}
	//printf("int_len = %d\n", int_len);
	while (int_len-- > 1)
		(*i)++;
}
