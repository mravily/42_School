/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:14:58 by mravily           #+#    #+#             */
/*   Updated: 2019/12/13 17:35:38 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_init_struct(t_tool_box *t_box)
{
	t_box->n_char_display = 0;
	t_box->pad_dir = LEFT;
	t_box->pad_zero = FALSE;
	t_box->len_padding = 0;
	t_box->len_precis = 0;
	t_box->precision = FALSE;
	t_box->asterix = FALSE;
	t_box->arg_neg = FALSE;
	t_box->str_convert = FALSE;
	t_box->char_convert = FALSE;
	t_box->addr_convert = FALSE;
	t_box->hexa_convert = FALSE;
	t_box->pad_space = FALSE;
	t_box->len_space = 0;
	t_box->digit = FALSE;
	t_box->empty_str = FALSE;
	t_box->convert_sign = FALSE;
}

static void		ft_parsing(const char *format,
va_list *ap, t_tool_box *t_box)
{
	size_t		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			t_box->convert_sign = TRUE;
			i++;
			ft_check_input(t_box, format, &i, ap);
		}
		else
		{
			write(1, &format[i], 1);
			t_box->n_char_display++;
		}
		i++;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_tool_box	*t_box;

	if (!(t_box = (t_tool_box*)malloc(sizeof(t_tool_box))))
		return (ERROR);
	ft_init_struct(t_box);
	va_start(ap, format);
	ft_parsing(format, &ap, t_box);
	va_end(ap);
	return (t_box->n_char_display);
}
