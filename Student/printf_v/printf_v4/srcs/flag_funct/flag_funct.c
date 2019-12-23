/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:10:13 by mravily           #+#    #+#             */
/*   Updated: 2019/12/23 17:08:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// ---       ".-0123456789*"     ---

void	set_funct_flag_tab(t_flag_funct *funct_flag_ptr)
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
}

size_t check_flag_point(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->point = true;
	return (1);
}

size_t check_flag_minus(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	flag->padding_direction = left;
	return (1);
}

size_t check_flag_zero(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	if (flag->zero == false)
		flag->zero = true;
	else
		flag->len_precision = ft_atoi(&(format[index]));
	return (1);
}

size_t handle_numeric_value_flag(const char *format, size_t index, t_flag *flag)
{
	if (flag->point == true)
		return (check_flag_len_precision(format, index, flag));
	else
		return (check_flag_len_padding(format, index, flag));
}

size_t check_flag_len_padding(const char *format, size_t index, t_flag *flag)
{
	flag->len_padding = ft_atoi(&(format[index]));
	return (ft_nbrlen(flag->len_padding, 10));
}

size_t check_flag_len_precision(const char *format, size_t index, t_flag *flag)
{
	//PRINTPOS;
	flag->len_precision = ft_atoi(&(format[index]));
	//printf("len_preci = %d\n", flag->len_precision);
	return (ft_nbrlen(flag->len_precision, 10));
}

size_t check_flag_asterisk(const char *format, size_t index, t_flag *flag)
{
	(void)format;
	(void)index;
	if (flag->point == true)
	{	
		flag->len_precision = va_arg(*(flag->arg), int);
		if (flag->len_precision < 0)
			flag->len_precision = flag->len_precision * (-1);	
	}
	else
		flag->len_padding = va_arg(*(flag->arg), int);
	if (flag->len_padding < 0)
	{
			flag->len_padding = flag->len_padding * (-1);
			flag->padding_direction = left;
	}
	return (1);
}
