/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_arg_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:21:43 by mravily           #+#    #+#             */
/*   Updated: 2019/12/12 16:47:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_resize_arg_2(t_data *data, va_list *ap, t_tool_box *t_box)
{
	if (t_box->lenght == LL)
	{
		if (t_box->digit == FALSE)
			data->u_ll_int = (unsigned long long int)va_arg(*ap, long long int);
		else
			data->ll_int = (long long int)va_arg(*ap, long long int);
	}
	else
	{
		if (t_box->digit == FALSE)
			data->ll_int = (unsigned int)va_arg(*ap, unsigned int);
		else
			data->ll_int = (int)va_arg(*ap, int);
	}
}

void			ft_resize_arg_1(t_data *data, va_list *ap, t_tool_box *t_box)
{
	if (t_box->lenght == HH)
	{
		if (t_box->digit == FALSE)
			data->u_ll_int = (unsigned char)va_arg(*ap, long long int);
		else
			data->ll_int = (char)va_arg(*ap, long long int);
	}
	else if (t_box->lenght == H)
	{
		if (t_box->digit == FALSE)
			data->u_ll_int = (unsigned short)va_arg(*ap, long long int);
		else
			data->ll_int = (short)va_arg(*ap, long long int);
	}
	else if (t_box->lenght == L)
	{
		if (t_box->digit == FALSE)
			data->u_ll_int = (unsigned long int)va_arg(*ap, long long int);
		else
			data->ll_int = (long int)va_arg(*ap, long long int);
	}
	else
		ft_resize_arg_2(data, ap, t_box);
}
