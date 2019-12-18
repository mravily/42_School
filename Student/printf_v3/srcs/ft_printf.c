/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:43:56 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 13:18:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_init_struct(t_tool_box *t_box)
{
	t_box->pad_dir = RIGHT;
	t_box->f_zero = FALSE;
	t_box->f_space = FALSE;
	t_box->f_precis = FALSE;
	t_box->len_pad = 0;
	t_box->len_pad = 0;
	t_box->c_digit = 0;
	t_box->c_char = 0;
	t_box->printed_char = 0;
	t_box->convert_sign = FALSE;
}


void		ft_basic_check(const char *format, va_list *ap, t_tool_box *t_box)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			t_box->convert_sign = TRUE;
			i++;
			//printf("i = %d\n", i);
			ft_parsing(format, ap, &i, t_box);
		}
		else
		{
			write(1, &format[i], 1);
			t_box->printed_char++;
		}
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_tool_box		*t_box;

	if (!(t_box = (t_tool_box *)malloc(sizeof(t_tool_box))))
		return (-1);
	va_start(ap, format);
	ft_init_struct(t_box);
	ft_basic_check(format, &ap, t_box);
	va_end(ap);
	return (t_box->printed_char);
}
