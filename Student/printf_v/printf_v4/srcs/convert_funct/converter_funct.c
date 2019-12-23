/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:43:16 by mravily           #+#    #+#             */
/*   Updated: 2019/12/23 17:02:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		set_funct_convert_tab(t_convert_funct *funct_convert_ptr)
{
	int i;

	i = 0;
	while (i < 127)
	{
		funct_convert_ptr[i] = NULL;
		i++;
	}
	funct_convert_ptr[0] = (void *)(-1);
	funct_convert_ptr['d'] = converter_d_i;
	funct_convert_ptr['i'] = converter_d_i;
	funct_convert_ptr['s'] = converter_str;
	funct_convert_ptr['c'] = converter_c;
	funct_convert_ptr['u'] = handle_x_X_converter;
	funct_convert_ptr['x'] = handle_x_X_converter;
	funct_convert_ptr['X'] = handle_x_X_converter;

}

void handle_x_X_converter(t_flag *flag, t_buffer *buffer)
{
	char 	*tmp;
	char	*to_add;
	int		len_arg;
	int		len_rest_precis;
	int		len_rest_padding;
	
	tmp = NULL;
	if (flag->converter == 'x')
	{
		resize_arg(flag);
		tmp = ft_convert_value_to_base("0123456789abcdef", flag);
		if (tmp[0] == '0' && flag->len_precision == 0)
			tmp = ft_strdup("");
		len_arg = ft_strlen(tmp);
		len_rest_precis = (flag->len_precision - len_arg);
		len_rest_padding = (flag->len_padding - len_arg);
		//printf("len_arg = %d\n", len_arg);
		//printf("len_rest_precs = %d\n", len_rest_precis);
		//printf("len_rest_padding = %d\n", len_rest_padding);
		if (len_arg < flag->len_precision)
		{
			//PRINTPOS;
			if (flag->arg_neg == true)
				flag->len_precision = flag->len_precision - 1;
			if (flag->padding_direction == left && flag->point == true)
				add_padding(&tmp, flag->zero, flag->len_precision - len_arg, right);
			else
				add_padding(&tmp, flag->zero, flag->len_precision - len_arg, flag->padding_direction);
			if (flag->arg_neg == true)
				ft_str_add_prefixe("-", &tmp);
		}
		else if (len_arg < flag->len_padding)
		{
			//PRINTPOS;
			to_add = ft_strnew_c(len_rest_padding, ' ');
			if(flag->padding_direction == left)
				ft_str_add_suffix(&tmp, to_add);
			else
				ft_str_add_prefixe(to_add, &tmp);
			//printf("tmp = |%s|\n", tmp);
		}
	}
	else if (flag->converter == 'X')
	{
		resize_arg(flag);
		tmp = ft_convert_value_to_base("0123456789ABCDEF", flag);
		len_arg = ft_strlen(tmp);
		if (len_arg < flag->len_precision)
		{
			if (flag->arg_neg == true)
				flag->len_precision = flag->len_precision - 1;
			if (flag->padding_direction == left && flag->point == true)
				add_padding(&tmp, flag->point, flag->len_precision - len_arg, right);
			else
				add_padding(&tmp, flag->point, flag->len_precision - len_arg, flag->padding_direction);
			if (flag->arg_neg == true)
				ft_str_add_prefixe("-", &tmp);
		}
		else if (len_arg < flag->len_padding)
		{
			//PRINTPOS;
			if (flag->arg_neg == true)
				flag->len_padding = flag->len_padding - 1;
			if (flag->arg_neg == true)
				ft_str_add_prefixe("-", &tmp);
			add_padding(&tmp, flag->zero, flag->len_padding - len_arg, flag->padding_direction);
		}
	}
	else if (flag->converter == 'u')
	{
		resize_arg(flag);
		tmp = ft_convert_value_to_base("0123456789", flag);
		len_arg = ft_strlen(tmp);
		if (len_arg < flag->len_precision)
		{
			if (flag->arg_neg == true)
				flag->len_precision = flag->len_precision - 1;
			if (flag->padding_direction == left && flag->point == true)
				add_padding(&tmp, flag->point, flag->len_precision - len_arg, right);
			else
				add_padding(&tmp, flag->point, flag->len_precision - len_arg, flag->padding_direction);
			if (flag->arg_neg == true)
				ft_str_add_prefixe("-", &tmp);
		}
		else if (len_arg < flag->len_padding)
		{
			//PRINTPOS;
			if (flag->arg_neg == true)
				flag->len_padding = flag->len_padding - 1;
			if (flag->arg_neg == true)
				ft_str_add_prefixe("-", &tmp);
			add_padding(&tmp, flag->zero, flag->len_padding - len_arg, flag->padding_direction);
		}
	}
	//printf("tmp = |%s|\n", tmp);
	add_str(buffer, tmp);
	free(tmp);
}

void		add_padding(char **result, BOOL to_test, int len, PAD_DIR direction)
{
	char			*to_add;
	
	if (to_test == false)
		to_add = ft_strnew_c(len, ' ');
	else
		to_add = ft_strnew_c(len, '0');

	if(direction == left)
		ft_str_add_suffix(result, to_add);
	else
		ft_str_add_prefixe(to_add, result);
}
