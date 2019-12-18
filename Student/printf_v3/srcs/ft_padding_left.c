/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 01:35:23 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 13:42:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_padding_left(t_tool_box *t_box, int i, long int len_arg)
{
	int max_pad;
	int j;

	i = (t_box->c_digit == TRUE) ? 0 : i;
	j = (t_box->len_precis < len_arg) ? len_arg : t_box->len_precis;
	max_pad = (t_box->c_digit == TRUE) ? t_box->len_pad - j : t_box->len_pad;
	printf("max_pad = %d\n", max_pad);
	while (i < max_pad)
	{
		write(1, " ", 1);
		t_box->printed_char++;
		i++;
	}
}
