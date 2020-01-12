/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:10:13 by mravily           #+#    #+#             */
/*   Updated: 2020/01/04 03:18:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		set_funct_flag_tab(t_flag_funct *funct_flag_ptr)
{
	int i;

	i = 0;
	while (i < 127)
	{
		funct_flag_ptr[i] = NULL;
		i++;
	}
	funct_flag_ptr[0] = (void *)(-1);
	funct_flag_ptr['.'] = check_flag_point;
	funct_flag_ptr['-'] = check_flag_minus;
	funct_flag_ptr['0'] = check_flag_zero;
	funct_flag_ptr['1'] = handle_numeric_value_flag;
	funct_flag_ptr['2'] = handle_numeric_value_flag;
	funct_flag_ptr['3'] = handle_numeric_value_flag;
	funct_flag_ptr['4'] = handle_numeric_value_flag;
	funct_flag_ptr['5'] = handle_numeric_value_flag;
	funct_flag_ptr['6'] = handle_numeric_value_flag;
	funct_flag_ptr['7'] = handle_numeric_value_flag;
	funct_flag_ptr['8'] = handle_numeric_value_flag;
	funct_flag_ptr['9'] = handle_numeric_value_flag;
	funct_flag_ptr['*'] = check_flag_asterisk;
	funct_flag_ptr['h'] = prefix_size;
	funct_flag_ptr['l'] = prefix_size;
}

size_t		prefix_size(const char *format, size_t index,
t_flag *flag)
{
	if (format[index] == 'h' && format[index + 1] == 'h')
	{
		flag->lenght_modif = HH;
		flag->pre_size = true;
	}
	else if (format[index] == 'h' && flag->pre_size == false)
	{
		flag->lenght_modif = H;
	}
	else if (format[index] == 'l' && format[index + 1] == 'l')
	{
		flag->lenght_modif = LL;
		flag->pre_size = true;
	}
	else if (format[index] == 'l' && flag->pre_size == false)
	{
		flag->lenght_modif = L;
	}
	return (1);
}

size_t		check_flag_len_precision(const char *format, size_t index,
t_flag *flag)
{
	flag->len_precision = ft_atoi(&(format[index]));
	return (ft_nbrlen(flag->len_precision, 10));
}

size_t		check_flag_asterisk(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->astrx = true;
	if (flag->point == true)
	{
		flag->len_precision = va_arg(*(flag->arg), int);
		if (flag->len_precision < 0)
			flag->point = false;
	}
	else
	{
		flag->len_padding = va_arg(*(flag->arg), int);
		if (flag->len_padding < 0)
		{
			flag->len_padding = flag->len_padding * (-1);
			flag->padding_direction = left;
		}
	}
	return (1);
}
