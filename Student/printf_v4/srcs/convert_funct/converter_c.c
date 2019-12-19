/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:36:18 by mravily           #+#    #+#             */
/*   Updated: 2019/12/19 21:12:52 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*converter_c(t_flag *flag)
{
	char	*result;
	char	_c_arg;
	int		len_arg;

	_c_arg = (char)va_arg(*(flag->arg), int);
	len_arg = 1;
	if (_c_arg == '\x00')
	{
		if (!(result = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		result[0] = '\x00';
		result[1] = '\0';
	}
	else
	{
		if (!(result = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		result[0] = (char)_c_arg;
		result[1] = '\0';
	}
	if (len_arg < flag->len_precision)
	{
		if (flag->padding_direction == left && flag->point == true)
			ft_padding(&result, flag->point, flag->len_precision - len_arg, right);
		else
			ft_padding(&result, flag->point, flag->len_precision - len_arg, flag->padding_direction);
	}
	else if (len_arg < flag->len_padding)
	{
		ft_padding(&result, flag->zero, flag->len_padding - len_arg, flag->padding_direction);
	}
	return (result);
}
