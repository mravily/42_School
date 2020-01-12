/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:59:27 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 18:03:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t		check_flag_point(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->point = true;
	return (1);
}

size_t		check_flag_minus(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->padding_direction = left;
	return (1);
}

size_t		check_flag_zero(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	if (flag->zero == false && flag->point == false)
		flag->zero = true;
	else
		flag->len_precision = ft_atoi(&(format[index]));
	return (1);
}

size_t		handle_numeric_value_flag(const char *format, size_t index,
t_flag *flag)
{
	if (flag->point == true)
		return (check_flag_len_precision(format, index, flag));
	else
		return (check_flag_len_padding(format, index, flag));
}

size_t		check_flag_len_padding(const char *format, size_t index,
t_flag *flag)
{
	flag->len_padding = ft_atoi(&(format[index]));
	return (ft_nbrlen(flag->len_padding, 10));
}
