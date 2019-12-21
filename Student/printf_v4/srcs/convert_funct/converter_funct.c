/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:43:16 by mravily           #+#    #+#             */
/*   Updated: 2019/12/21 18:56:14 by mravily          ###   ########.fr       */
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
	char *tmp;
	if (flag->converter == 'x')
	{
		resize_arg(flag);
		tmp = ft_convert_value_to_base("0123456789abcdef", flag);
	}
	else if (flag->converter == 'X')
	{
		resize_arg(flag);
		tmp = ft_convert_value_to_base("0123456789ABCDEF", flag);
	}
	else if (flag->converter == 'u')
	{
		resize_arg(flag);
		tmp = ft_convert_value_to_base("0123456789", flag);
	}
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
