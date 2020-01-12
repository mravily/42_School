/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:36:18 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 22:13:52 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		add_padding_char(char **result, t_flag *flag, int c_arg,
t_buffer *buffer)
{
	char	*to_add;
	int		len_arg;

	len_arg = 1;
	to_add = NULL;
	if (len_arg < flag->len_padding)
	{
		to_add = ft_strnew_c(flag->len_padding - len_arg, ' ');
		if (flag->padding_direction == left)
			ft_str_add_suffix(result, to_add);
		else
			ft_str_add_prefixe(to_add, result);
	}
	if (c_arg == '\x00')
	{
		if (flag->padding_direction == left)
			add_char(buffer, '\0');
		if (len_arg < flag->len_padding)
			add_str(buffer, *result);
		if (flag->padding_direction == right)
			add_char(buffer, '\0');
	}
	else
		add_str(buffer, *result);
	free(to_add);
}

void			converter_c(t_flag *flag, t_buffer *buffer)
{
	char	*result;
	int		c_arg;
	int		len_arg;

	c_arg = (char)va_arg(*(flag->arg), int);
	len_arg = 1;
	if (c_arg == '\x00')
		result = ft_strnew(0);
	else
	{
		if (!(result = (char*)malloc(sizeof(char) * 2)))
			return ;
		result[0] = c_arg;
		result[1] = '\0';
	}
	add_padding_char(&result, flag, c_arg, buffer);
	free(result);
}
