/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:26:25 by mravily           #+#    #+#             */
/*   Updated: 2019/12/21 19:02:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		resize_arg_2(t_flag *flag)
{
	if (flag->lenght_modif == LL)
	{
		if (flag->converter != 'd')
			flag->data.u_ll_int = (unsigned long long int)va_arg(*(flag->arg), long long int);
		else
			flag->data.ll_int = (long long int)va_arg(*(flag->arg), long long int);
	}
	else
	{
		if (flag->converter != 'd')
			flag->data.ll_int = (unsigned int)va_arg(*(flag->arg), unsigned int);
		else
			flag->data.ll_int = (int)va_arg(*(flag->arg), int);
	}
}

void			resize_arg(t_flag *flag)
{
	if (flag->lenght_modif == HH)
	{
		if (flag->converter != 'd')
			flag->data.u_ll_int = (unsigned char)va_arg(*(flag->arg), long long int);
		else
			flag->data.ll_int = (char)va_arg(*(flag->arg), long long int);
	}
	else if (flag->lenght_modif == H)
	{
		if (flag->converter != 'd')
			flag->data.u_ll_int = (unsigned short)va_arg(*(flag->arg), long long int);
		else
			flag->data.ll_int = (short)va_arg(*(flag->arg), long long int);
	}
	else if (flag->lenght_modif == L)
	{
		if (flag->converter != 'd')
			flag->data.u_ll_int = (unsigned long int)va_arg(*(flag->arg), long long int);
		else
			flag->data.ll_int = (long int)va_arg(*(flag->arg), long long int);
	}
	else
		resize_arg_2(flag);
}
