/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:49:12 by mravily           #+#    #+#             */
/*   Updated: 2019/12/16 16:54:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_struct_init(t_tool_box *t_box)
{
	t_box->len_zero = 0;
	t_box->len_space = 0;
	t_box->len_precis = 0;
	t_box->len_asterix = 0;
	t_box->len_field_width = 0;
	t_box->pad_dir = LEFT;
	t_box->f_zero = FALSE;
	t_box->f_space = FALSE;
	t_box->f_precis = FALSE;
	t_box->f_asterix = FALSE;
	t_box->f_field_width = FALSE;
	t_box->c_digit = FALSE;
	t_box->lenght_modif = 0;
	t_box->cmpt_char = 0;

	t_box->flag = FALSE;
	t_box->empty_str = FALSE;
	t_box->arg_neg = FALSE;
	t_box->sign_convert = FALSE;
}

void			ft_check_flag(const char *format, size_t *i, t_tool_box *t_box, va_list *ap)
{
	if (format[*i] == '-')
	{
		//PRINTPOS;
		t_box->flag = TRUE;
		t_box->pad_dir = RIGHT;
		t_box->f_space = TRUE;
		t_box->len_space = ft_atoi_index(format + *i);
		ft_int_len(t_box->len_space, i);
		//PRINT_I;
	}
	else if (format[*i] == '0')
	{
		t_box->flag = TRUE;
		t_box->f_zero = TRUE;
		t_box->len_zero = ft_atoi_index(format + *i);
		ft_int_len(t_box->len_zero, i);
		//PRINT_I;
	}
	else if (format[*i] == '.')
	{
		//PRINTPOS;
		t_box->f_precis = TRUE;
		t_box->len_precis = ft_atoi_index(format + *i);
		//PRINT_PREC;
		ft_int_len(t_box->len_precis, i);
		//PRINT_I;
		if ((t_box->len_precis == 0 &&
		format[*i + 1] >= '0' && format[*i + 1] <= '9' )||
		(t_box->f_precis == 1 && format[*i + 1] >= '0' && format[*i + 1] <= '9'))
			(*i)++;
		//PRINT_I;
	}
	else if (format[*i] == '*')
	{	
		//PRINTPOS;
		t_box->flag = TRUE;
		t_box->f_asterix = TRUE;
		t_box->len_asterix = va_arg(*ap, int);
		//printf("len_atx = %d\n", t_box->len_asterix);
	}
	else if (ft_isdigit(format[*i]) == 1)
	{
		//PRINTPOS;
		t_box->flag = TRUE;
		t_box->f_field_width = TRUE;
		t_box->len_field_width = ft_atoi_index(format + *i);
		//PRINT_FIELD;
		ft_int_len(t_box->len_field_width, i);
		//PRINT_I;
	}
}

void			ft_check_convert(const char *format, size_t *i, t_tool_box *t_box, va_list *ap, t_data *u_data)
{
	if (format[*i] == 'c')
	{
		ft_print_arg(t_box, ft_printchar(va_arg(*ap, int)));
	}
	else if (format[*i] == 's')
	{
		ft_print_arg(t_box, ft_printstr(va_arg(*ap, char *), t_box));
	}
	else if (format[*i] == 'd' || format[*i] == 'i')
	{
		t_box->c_digit = TRUE;
		ft_resize_arg_1(u_data, ap, t_box);
		ft_print_arg(t_box, ft_itoa(u_data, t_box));
	}
	else if (format[*i] == 'p')
	{
		ft_resize_arg_1(u_data, ap, t_box);
		ft_print_arg_addr(t_box,
		ft_print_addr(va_arg(*ap, void *), "0123456789abcdef"));
	}
	else if (format[*i] == 'u')
	{
		ft_resize_arg_1(u_data, ap, t_box);
		ft_print_arg(t_box,
		ft_convert_value_to_base(u_data, "0123456789", t_box));
	}
	else if (format[*i] == 'x')
	{
		ft_resize_arg_1(u_data, ap, t_box);
		ft_print_arg(t_box,
		ft_convert_value_to_base(u_data, "0123456789abcdef", t_box));
	}
	else if (format[*i] == 'X')
	{
		ft_resize_arg_1(u_data, ap, t_box);
		ft_print_arg(t_box,
		ft_convert_value_to_base(u_data, "0123456789ABCDEF", t_box));
	}
}

void			ft_check_input(const char *format, size_t *i,
t_tool_box *t_box, va_list *ap)
{
	t_data		u_data;

	while (format[*i])
	{
		//PRINT_IW;
		//PRINT_CIW;
		if (t_box->sign_convert == TRUE && (format[*i] == '-' || format[*i] == '0' || format[*i] == '.'
		|| format[*i] == '*' || ft_isdigit(format[*i]) == 1))
		{
			//PRINTPOS;
			//PRINT_I;
			//PRINT_CIW;
			ft_check_flag(format, i, t_box, ap);
		}
		//printf("format = %c\n", format[*i]);
		//printf("sign_conver = %d\n", t_box->sign_convert);
		if (t_box->sign_convert == TRUE && (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'd'
		|| format[*i] == 'i' || format[*i] == 'u' || format[*i] == 'x'
		|| format[*i] == 'X' || format[*i] == 'p'))
		{
			//PRINTPOS;
			//PRINT_I;
			ft_check_convert(format, i, t_box, ap, &u_data);
			return ;
		}
		if (t_box->sign_convert == TRUE && format[*i - 1] == '%' && format[*i] == '%')
		{
			write(1, "%", 1);
			t_box->cmpt_char++;
			return ;
		}
		//PRINT_CIW;
		//PRINT_I;
		++(*i);
	}
}

static void		ft_parsing(const char *format, t_tool_box *t_box, va_list *ap)
{
	size_t		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			t_box->sign_convert = TRUE;
			ft_check_input(format, &i, t_box, ap);
		}
		else
		{
			write(1, &format[i], 1);
			t_box->cmpt_char++;
		}
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_tool_box	*t_box;

 
	va_start(ap, format);
	ft_struct_init(t_box);
	ft_parsing(format, t_box, &ap);
	va_end(ap);
	return (t_box->cmpt_char);
}