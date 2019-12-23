/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:52:22 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 10:53:43 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_padding_zero(t_tool_box *t_box, char *arg, int *i)
{
	long int	j;
	int			n;

	n = 0;
	j = ft_strlen(arg);
	if (arg[0] == '-' && t_box->len_pad - j > 0)
	{
		*i = *i + 1;
		write(1, "-", 1);
		t_box->printed_char++;
	}
	while (n < t_box->len_pad - j)
	{
		write(1, "0", 1);
		t_box->printed_char++;
		n++;
	}
}
