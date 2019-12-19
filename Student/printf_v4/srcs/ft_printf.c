/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:24:13 by mravily           #+#    #+#             */
/*   Updated: 2019/12/19 21:08:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		parse_flag(char *format, size_t index, t_flag *flag)
{
	static t_flag_funct funct_flag_ptr[255] = {NULL};
	size_t				flag_len;

	if (funct_flag_ptr[0] == NULL)
		set_funct_flag_tab(funct_flag_ptr);

	flag_len = 0;
	index++;
	while (ft_strcmp_c(".-0123456789*", format[index + flag_len]) == true)
	{
		flag_len += funct_flag_ptr
		[format[index + flag_len]](format, index + flag_len, flag);
	}
	return (flag_len + 1);
}

int			ft_printf(char *format, ...)
{
	static t_convert_funct funct_convert_ptr[255] = {NULL};
	size_t index;
	size_t flag_len;
	char c;
	va_list arg;
	char *to_print;
	t_flag flag;
	char *result;

	if (funct_convert_ptr[0] == NULL)
		set_funct_convert_tab(funct_convert_ptr);

	va_start(arg, format);
	flag = create_t_flag(&arg);
	index = 0;
	result = ft_strnew(0);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			flag_len = parse_flag(format, index, &flag);
			print_flag(&flag);
			c = format[index + flag_len];
			if (funct_convert_ptr[c] != NULL)
				to_print = funct_convert_ptr[c](&flag);
			else
				to_print = ft_strsub(format, index + 1, flag_len);
			index += flag_len;
		}
		else
			to_print = ft_strdup_c(format[index]);

		ft_str_add_suffix(&result, to_print);
		free(to_print);
		index++;
	}
	va_end(arg);
	write(1, result, ft_strlen(result));
	return (ft_strlen(result));
}
