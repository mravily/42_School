/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:21:23 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 13:49:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_check_flags_2(t_tool_box *t_box, const char *format, size_t *i, va_list *ap)
{
	if (format[*i] == '*')
	{
		//PRINTPOS;
		//PRINT_IW;
		t_box->f_asterisk = TRUE;
		if (t_box->f_precis == TRUE)
		{
		//PRINTPOS;
		t_box->len_precis = va_arg(*ap, int);
		//PRINT_PREC;
		}
		else
		{
			//PRINTPOS;
			t_box->len_pad = va_arg(*ap, int);
		}
		if (t_box->len_pad < 0)
		{
			//PRINTPOS;
			t_box->len_pad *= -1;
			t_box->pad_dir = LEFT;
		}
		//PRINT_IW;
	}
	else if (ft_isdigit(format[*i]) == 1 && format[*i - 1] == '%')
	{
		//PRINTPOS;
		//PRINT_IW;
		ft_get_padding(t_box, format, i);
		//PRINT_IW;
	}
}

static void		ft_check_flags(t_tool_box *t_box, const char *format, size_t *i, va_list *ap)
{
	if (format[*i] == '-')
	{
		//PRINTPOS;
		//PRINT_IW;
		t_box->pad_dir = LEFT;
		(*i)++;
		ft_get_padding(t_box, format, i);
		//PRINT_IW;
	}
	else if (format[*i] == '0')
	{
		t_box->f_zero = TRUE;
		(*i)++;
		ft_get_padding(t_box, format, i);
	}
	else if (format[*i] == '.')
	{
		//PRINTPOS;
		//PRINT_IW;
		t_box->f_precis = TRUE;
		(*i)++;
		ft_get_padding(t_box, format, i);
		//PRINT_IW;
	}
	ft_check_flags_2(t_box, format, i, ap);
}

static void			ft_check_convert_2(const char *format, t_tool_box *t_box,
va_list *ap, t_data *u_data)
{
	if (*format == 'u')
	{
		t_box->c_digit = TRUE;
		ft_resize_arg(u_data, ap, t_box);
		ft_print_arg(t_box,
		ft_convert_value_to_base(u_data, "0123456789", t_box));
	}
	else if (*format == 'x')
	{
		ft_resize_arg(u_data, ap, t_box);
		ft_print_arg(t_box,
		ft_convert_value_to_base(u_data, "0123456789abcdef", t_box));
	}
	else if (*format == 'X')
	{
		//PRINTPOS;
		ft_resize_arg(u_data, ap, t_box);
		ft_print_arg(t_box,
		ft_convert_value_to_base(u_data, "0123456789ABCDEF", t_box));
	}
}

static void			ft_check_convert(const char *format, t_tool_box *t_box,
va_list *ap, t_data *u_data)
{
	
	if (*format == 'c')
	{
		//PRINTPOS;
		//PRINT_PD;
		t_box->c_char = TRUE;
		ft_print_arg(t_box, ft_printchar(va_arg(*ap, int)));
	}
	else if (*format == 's')
	{
		ft_print_arg_str(t_box, ft_printstr(va_arg(*ap, char *)));
	}
	else if (*format == 'd' || *format == 'i')
	{
		t_box->c_digit = TRUE;
		ft_resize_arg(u_data, ap, t_box);
		ft_print_arg(t_box, ft_itoa(u_data));
	}
	else if (*format == 'p')
	{
		ft_resize_arg(u_data, ap, t_box);
		ft_print_arg_addr(t_box,
		ft_print_addr(va_arg(*ap, void *), "0123456789abcdef"));
	}
	else
		ft_check_convert_2(format, t_box, ap, u_data);
}

void		ft_parsing(const char *format, va_list *ap, size_t *i,
t_tool_box *t_box)
{
	t_data		u_data;

	while (format[*i])
	{
		if (t_box->convert_sign == TRUE && (format[*i] == '-'
		|| format[*i] == '0' || format[*i] == '.' || format[*i] == '*'
		|| ft_isdigit(format[*i]) == 1))
		{
			//PRINTPOS;
			//PRINT_IW;
			//PRINT_CIW;
			ft_check_flags(t_box, format, i, ap);
		}
		//printf("format = %c\n", format[*i]);
		//printf("sign_conver = %d\n", t_box->sign_convert);
		if (t_box->convert_sign == TRUE && (format[*i] == 'c' ||
		format[*i] == 's' || format[*i] == 'd' || format[*i] == 'i' ||
		format[*i] == 'u' || format[*i] == 'x' || format[*i] == 'X' ||
		format[*i] == 'p'))
		{
			//PRINTPOS;
			//PRINT_IW;
			//PRINT_CIW;
			ft_check_convert(format + *i, t_box, ap, &u_data);
			return ;
		}
		if (t_box->convert_sign == TRUE && format[*i] == '%')
		{
			//PRINTPOS;
			write(1, "%", 1);
			t_box->printed_char++;
			return ;
		}
		//PRINT_CIW;
		//PRINT_I;
		++(*i);
	}
}
