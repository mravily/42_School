/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:14:58 by mravily           #+#    #+#             */
/*   Updated: 2019/11/23 14:40:23 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_tool_box	*t_box;
	size_t		i;

	if (!(t_box = (t_tool_box*)malloc(sizeof(t_tool_box))))
		return (ERROR);
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_input(format, );
		}
		else
		{
			write(1, &format[i], 1);
			t_box->n_character_display++;
		}
		i++;
	}
	return (t_box->n_character_display);
}
