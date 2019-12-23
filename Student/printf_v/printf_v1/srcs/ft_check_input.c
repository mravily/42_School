/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:21:38 by mravily           #+#    #+#             */
/*   Updated: 2019/12/13 19:13:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_check_convert_2(t_tool_box *t_box, const char *format,
va_list *ap, t_data *data)
{
	if (*format == 'u')
	{
		ft_resize_arg_1(data, ap, t_box);
		ft_print_arg(t_box,
			ft_convert_value_to_base(data, "0123456789", t_box));
	}
	else if (*format == 'x')
	{
		ft_resize_arg_1(data, ap, t_box);
		ft_print_arg(t_box,
			ft_convert_value_to_base(data, "0123456789abcdef", t_box));
	}
	else if (*format == 'X')
	{
		ft_resize_arg_1(data, ap, t_box);
		ft_print_arg(t_box,
			ft_convert_value_to_base(data, "0123456789ABCDEF", t_box));
	}
	else if (*format == '%' && t_box->convert_sign == TRUE)
	{
		//PRINTPOS;
		ft_print_arg(t_box, ft_printchar(37));
	}
}

static void		ft_check_convert_1(t_tool_box *t_box, const char *format,
va_list *ap, t_data *data)
{
	if (*format == 'c')
	{
		t_box->char_convert = TRUE;
		ft_print_arg(t_box, ft_printchar(va_arg(*ap, int)));
	}
	else if (*format == 's')
	{
		t_box->str_convert = TRUE;
		ft_print_arg(t_box, ft_printstr(va_arg(*ap, char *), t_box));
	}
	else if (*format == 'p')
	{
		t_box->addr_convert = TRUE;
		ft_print_arg_addr(t_box, ft_print_addr(va_arg(*ap, void *), "0123456789abcdef"));
	}
	else if (*format == 'd' || *format == 'i')
	{
		t_box->digit = TRUE;
		ft_resize_arg_1(data, ap, t_box);
		ft_print_arg(t_box, ft_itoa(data, t_box));
	}
	else
		ft_check_convert_2(t_box, format, ap, data);
}

static void		ft_check_flags(t_tool_box *t_box, const char *format,
	size_t *i, va_list *ap)
{
	int		j;

	j = 0;
	if (format[*i] == '0' && format[*i - 1] == '%')
	{
		t_box->pad_zero = TRUE;
		t_box->len_padding += ft_atoi(format + *i);
		//printf("1st_len_padding = %d\n", t_box->len_padding);
	}
	else if (ft_isdigit(format[*i]))
	{
		//PRINTPOS;
		//printf("i = %zu\n", *i);
		t_box->pad_space = TRUE;
		//printf("1st_pad_space = %d\n", t_box->pad_space);
		t_box->len_padding += ft_atoi(format + *i);
		//printf("2nd_len_padding = %d\n", t_box->len_padding);
		j = ft_int_len(t_box->len_padding);
		//printf("j = %d\n", j);
		//printf("2nd2_len_padding = %d\n", t_box->len_padding);
		while (j-- > 1)
			++(*i);
		//printf("a_w_i = %zu\n", *i);
	}
	else if (format[*i] == '-')
	{
		//PRINTPOS;
		//printf("i = %zu\n", *i);
		t_box->pad_dir = RIGHT;
		t_box->len_padding += ft_atoi(format + *i);
		//printf("3rd_len_padding = %d\n", t_box->len_padding);
	}
	else if (format[*i] == '.')
	{
		//PRINTPOS;
		//printf("i = %zu\n", *i);
		t_box->precision = TRUE;
		t_box->len_padding += ft_atoi(format + *i);
		//printf("4th_len_padding = %d\n", t_box->len_padding);
		j = ft_int_len(t_box->len_padding);
		//printf("j = %d\n", j);
		//printf("2nd2_len_padding = %d\n", t_box->len_padding);
		while (j-- > 1)
			++(*i);
		//printf("a_w_i = %zu\n", *i);
	}
	else if (format[*i] == '*')
	{
		PRINTPOS;
		//printf("i = %zu\n", *i);
		t_box->pad_space = TRUE;
		t_box->len_padding += va_arg(*ap, int);
		//printf("5th_len_padding = %d\n", t_box->len_padding);
	}
}

static void		ft_prefix_size(t_tool_box *t_box, const char *format, size_t *i)
{
	if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		t_box->lenght = HH;
		++(*i);
	}
	else if (format[*i] == 'h' && format[*i + 1] != 'h')
	{
		t_box->lenght = H;
	}
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		t_box->lenght = LL;
		++(*i);
	}
	else if (format[*i] == 'l' && format[*i + 1] != 'l')
	{
		t_box->lenght = L;
	}
}

void			ft_check_input(t_tool_box *t_box, const char *format,
size_t *i, va_list *ap)
{
	t_data		data;

	//printf("1st_i = %zu\n", *i);
	while (format[*i])
	{
		if (format[*i] == '-' || format[*i] == '0' || format[*i] == '.' ||
		format[*i] == '*' || ft_isdigit(format[*i]) == 1)
		{
			//PRINTPOS;
			//printf("2nd_i = %zu\n", *i);
			ft_check_flags(t_box, format, i, ap);
			//printf("3nd_i = %zu\n", *i);
		}
		//printf("4nd_i = %zu\n", *i);
		/*
		else if (format[*i] == 'h' || format[*i] == 'l')
		{
			PRINTPOS;
			ft_prefix_size(t_box, format, i);
		}
		*/
		//printf("5nd_i = %zu\n", *i);
		if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' ||
		format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u' ||
		format[*i] == 'x' || format[*i] == 'X')
		{
			//PRINTPOS;
			//printf("6nd_i = %zu\n", *i);
			ft_check_convert_1(t_box, format + *i, ap, &data);
			return ;
		}
		
		if (format[*i] == '%' && format[*i - 1] == '%')
		{
			//PRINTPOS;
			ft_check_convert_1(t_box, format + *i, ap, &data);
			return ;
		}
		++(*i);
	}
}
