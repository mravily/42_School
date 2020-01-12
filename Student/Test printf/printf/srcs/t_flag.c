/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:28:24 by mravily           #+#    #+#             */
/*   Updated: 2020/01/04 03:16:49 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flag		create_t_flag(va_list *arg)
{
	t_flag result;

	result.arg = arg;
	result.point = false;
	result.digit = false;
	result.zero = false;
	result.arg_neg = false;
	result.astrx = false;
	result.pre_size = false;
	result.padding_direction = right;
	result.len_padding = -1;
	result.len_precision = -1;
	result.lenght_modif = -1;
	return (result);
}

t_flag		*malloc_t_flag(va_list *arg)
{
	t_flag *result;

	result = (t_flag *)malloc(sizeof(t_flag));
	if (result == NULL)
		return (NULL);
	*result = create_t_flag(arg);
	return (result);
}

void		reset_t_flag(t_flag *flag)
{
	flag->point = false;
	flag->zero = false;
	flag->digit = false;
	flag->arg_neg = false;
	flag->astrx = false;
	flag->pre_size = false;
	flag->padding_direction = right;
	flag->len_padding = -1;
	flag->len_precision = -1;
	flag->lenght_modif = -1;
}
