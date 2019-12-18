/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:51:08 by mravily           #+#    #+#             */
/*   Updated: 2019/12/07 14:20:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_padding(t_tool_box *t_box, int len_arg)
{
	int		len_to_display;
	int		len_pad;
	char	sign[2];

	//TEST6
	len_to_display = 0;
	len_pad = 0;
	//printf("pad_zero = %d\n", t_box->pad_zero);
	//printf("pad_space = %d\n", t_box->pad_space);
	//printf("pad_dir = %d\n", t_box->pad_dir);
	if ((t_box->pad_zero == TRUE && t_box->pad_space == FALSE) || (t_box->precision == TRUE && t_box->pad_space == FALSE))
	{
		//PRINTPOS;
		sign[0] = (char)'0';
		len_pad = t_box->len_padding;
	}
	else if ((t_box->pad_space == TRUE && t_box->pad_zero == FALSE) || t_box->pad_dir == RIGHT)
	{
		//PRINTPOS;
		len_pad = t_box->len_padding;
		sign[0] = (char)' ';
	}
	//printf("len_arg = %d\n", len_arg);
	if (len_pad < 0)
		len_pad *= (-1);
	//printf("len_pad = %d\n", len_pad);
	len_to_display = (len_pad - len_arg);
	if (len_to_display < 0)
		len_to_display *= (-1);
	//printf("len_display = %d\n", len_to_display);
	//printf("sign = %c\n", sign);
	if (t_box->arg_neg == TRUE && t_box->pad_space == FALSE && t_box->addr_convert == FALSE)
	{
		if (t_box->pad_dir == LEFT)
		{
			//PRINTPOS;
			write(1, "-", 1);
			t_box->n_char_display++;
		}
		if (t_box->precision != TRUE)
		len_to_display -= 1;
	}
	if (t_box->addr_convert == TRUE && t_box->precision == FALSE)
		len_to_display -= 2;
	//printf("b_W_len_display = %d\n", len_to_display);
	while (len_to_display > 0)
	{
		write(1, &sign, 1);
		t_box->n_char_display++;
		len_to_display--;
	}
	//PRINTPOS;
}
