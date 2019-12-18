/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:09:16 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 14:20:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_padding_right(t_tool_box *t_box, int i, long int len)
{
	int max_pad;
	int j;

	i = (t_box->c_digit == TRUE) ? 0 : i;
	j = (t_box->len_precis < len) ? len : t_box->len_precis;
	max_pad = (t_box->c_digit == TRUE) ? t_box->len_pad - j : t_box->len_pad;
	while (i < max_pad)
	{
		write(1, " ", 1);
		t_box->cmpt_char++;
		i++;
	}
}
