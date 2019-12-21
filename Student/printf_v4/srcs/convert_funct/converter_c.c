/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:36:18 by mravily           #+#    #+#             */
/*   Updated: 2019/12/21 18:37:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void converter_c(t_flag *flag, t_buffer *buffer)
{
	char	*result;
	int		_c_arg;
	int		len_arg;

	_c_arg = (char)va_arg(*(flag->arg), int);
	len_arg = 1;
	if (_c_arg == '\x00')
		result = ft_strnew(0);
	else
	{
		if (!(result = (char*)malloc(sizeof(char) * 2)))
			return ;
		result[0] = _c_arg;
		result[1] = '\0';
	}
	if (len_arg < flag->len_padding)
	{
		add_padding(&result, flag->zero, flag->len_padding - len_arg, flag->padding_direction);
	}
	//printf("result = %s\n", result);

	add_str(buffer, result);
	free(result);
	if (_c_arg == '\x00')
		add_char(buffer, '\0');
}
