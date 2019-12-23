/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 00:50:59 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 14:51:22 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_padding_zero(t_tool_box *t_box, char *arg, int len_arg)
{
	int			j;

	if (arg[0] == '-' && t_box->len_pad - len_arg > 0)
	{
		write(1, "-", 1);
		t_box->cmpt_char++;
	}
	while (j < (t_box->len_pad - len_arg))
	{
		write(1, "0", 1);
		t_box->cmpt_char++;
		j++;
	}
}
