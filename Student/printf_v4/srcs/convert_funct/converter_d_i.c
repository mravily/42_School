/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:30:57 by mravily           #+#    #+#             */
/*   Updated: 2019/12/21 18:29:01 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void converter_d_i(t_flag *flag, t_buffer *buffer)
{
	
	long long int	value;
	char 			*result;
	int 			len_arg;

	//PRINTPOS;
	value = va_arg(*(flag->arg), int);
	//PRINTPOS;
	if (value < 0)
	{
		flag->arg_neg = true;
		value *= (-1);
	}
	result = ft_itoa(value);
	len_arg = ft_strlen(result);
	//printf("len_arg = %d\n", len_arg);
	if (len_arg < flag->len_precision)
	{
		if (flag->arg_neg == true)
			flag->len_precision = flag->len_precision - 1;
		if (flag->padding_direction == left && flag->point == true)
			add_padding(&result, flag->point, flag->len_precision - len_arg, right);
		else
			add_padding(&result, flag->point, flag->len_precision - len_arg, flag->padding_direction);
		if (flag->arg_neg == true)
			ft_str_add_prefixe("-", &result);
	}
	else if (len_arg < flag->len_padding)
	{
		//PRINTPOS;
		if (flag->arg_neg == true)
			flag->len_padding = flag->len_padding - 1;
		if (flag->arg_neg == true)
			ft_str_add_prefixe("-", &result);
		add_padding(&result, flag->zero, flag->len_padding - len_arg, flag->padding_direction);
	}

	add_str(buffer, result);
	free(result);
}
