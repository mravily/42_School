/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:24:13 by mravily           #+#    #+#             */
/*   Updated: 2019/12/21 19:52:40 by mravily          ###   ########.fr       */
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
		flag_len += funct_flag_ptr[format[index + flag_len]](format, index + flag_len, flag);
	}
	flag->converter = format[index + flag_len];
	return (flag_len + 1);
}

int			ft_printf(char *format, ...)
{
	static t_convert_funct funct_convert_ptr[255] = {NULL};
	size_t index;
	size_t flag_len;
	char c;
	t_buffer buffer;
	va_list arg;
	t_flag flag;
	char *tmp;

	if (funct_convert_ptr[0] == NULL)
		set_funct_convert_tab(funct_convert_ptr);

	va_start(arg, format);
	flag = create_t_flag(&arg);
	index = 0;
	buffer = create_buffer(400);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			flag_len = parse_flag(format, index, &flag);
			//print_flag(&flag);
			c = format[index + flag_len];
			if (funct_convert_ptr[c] != NULL)
				funct_convert_ptr[c](&flag, &buffer);
			else
			{
				tmp = ft_strsub(format, index + 1, flag_len);
				add_str(&buffer, tmp);
				free(tmp);
			}
			index += flag_len;
			reset_t_flag(&flag);
		}
		else
			add_char(&buffer, format[index]);
		index++;
	}
	va_end(arg);
	print_text(&buffer);
	return (buffer.total_len);
}
