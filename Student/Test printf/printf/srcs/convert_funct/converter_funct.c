/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:43:16 by mravily           #+#    #+#             */
/*   Updated: 2020/01/04 03:44:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		set_funct_convert_tab(t_convert_funct *funct_convert_ptr)
{
	int i;

	i = 0;
	while (i < 127)
	{
		funct_convert_ptr[i] = NULL;
		i++;
	}
	funct_convert_ptr[0] = (void *)(-1);
	funct_convert_ptr['d'] = converter_digit;
	funct_convert_ptr['i'] = converter_digit;
	funct_convert_ptr['s'] = converter_str;
	funct_convert_ptr['c'] = converter_c;
	funct_convert_ptr['u'] = handle_unsigned_converter;
	funct_convert_ptr['x'] = handle_x_converter;
	funct_convert_ptr['X'] = handle_hexa_converter;
	funct_convert_ptr['p'] = handle_addr_converter;
}

void		handle_addr_converter(t_flag *flag, t_buffer *buffer)
{
	char	*result;
	int		len_arg;
	char	*to_add;

	result = ft_print_addr(va_arg(*(flag->arg), void *), "0123456789abcdef");
	to_add = "0x";
	ft_str_add_prefixe(to_add, &result);
	len_arg = ft_strlen(result);
	if (flag->point == true && flag->len_precision == 0 && result[0] == '0')
	{
		if (flag->len_padding >= len_arg)
		{
			free(result);
			result = ft_strnew_c(flag->len_padding, ' ');
		}
		else
		{
			free(result);
			return ;
		}
	}
	else
		add_padding_digit(&result, flag, len_arg);
	add_str(buffer, result);
	free(result);
}

void		handle_x_converter(t_flag *flag, t_buffer *buffer)
{
	char	*result;
	int		len_arg;

	resize_arg(flag);
	result = ft_convert_value_to_base("0123456789abcdef", flag);
	len_arg = ft_strlen(result);
	if (flag->point == true && flag->len_precision == 0 && result[0] == '0')
	{
		if (flag->len_padding >= len_arg)
		{
			free(result);
			result = ft_strnew_c(flag->len_padding, ' ');
		}
		else
		{
			free(result);
			return ;
		}
	}
	else
		add_padding_digit(&result, flag, len_arg);
	add_str(buffer, result);
	free(result);
}

void		handle_hexa_converter(t_flag *flag, t_buffer *buffer)
{
	char	*result;
	int		len_arg;

	resize_arg(flag);
	result = ft_convert_value_to_base("0123456789ABCDEF", flag);
	len_arg = ft_strlen(result);
	if (flag->point == true && flag->len_precision == 0 && result[0] == '0')
	{
		if (flag->len_padding >= len_arg)
		{
			free(result);
			result = ft_strnew_c(flag->len_padding, ' ');
		}
		else
		{
			free(result);
			return ;
		}
	}
	else
		add_padding_digit(&result, flag, len_arg);
	add_str(buffer, result);
	free(result);
}

void		add_padding(char **result, t_flag *flag, int len)
{
	char			*to_add;

	if (flag->point == true || flag->padding_direction == left)
		to_add = ft_strnew_c(len, ' ');
	else
		to_add = ft_strnew_c(len, '0');
	if (flag->padding_direction == left)
		ft_str_add_suffix(result, to_add);
	else
		ft_str_add_prefixe(to_add, result);
	free(to_add);
}
