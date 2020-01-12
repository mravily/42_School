/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:35:49 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 22:11:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		add_padding_str(char **result, t_flag *flag, int len_arg)
{
	char	*to_add;

	to_add = NULL;
	if (flag->point == true)
	{
		if (flag->point == true && flag->len_precision == -1)
			flag->len_precision = 0;
		if (len_arg <= flag->len_padding)
		{
			to_add = ft_strnew_c(flag->len_padding - len_arg, ' ');
			if (flag->padding_direction == left)
				ft_str_add_suffix(result, to_add);
			else
				ft_str_add_prefixe(to_add, result);
		}
	}
	else if (len_arg < flag->len_padding)
	{
		to_add = ft_strnew_c(flag->len_padding - len_arg, ' ');
		if (flag->padding_direction == left)
			ft_str_add_suffix(result, to_add);
		else
			ft_str_add_prefixe(to_add, result);
	}
	free(to_add);
}

static char		*check_arg(char *result, t_flag *flag, char *arg)
{
	if (arg == NULL)
	{
		if (flag->point == true && flag->len_precision >= 0)
		{
			if (flag->point == true && flag->len_precision == -1)
				flag->len_precision = 0;
			result = ft_strncpy("(null)", flag->len_precision);
		}
		else
			result = ft_strdup("(null)");
	}
	else
	{
		if (flag->point == true && flag->len_precision == -1)
			flag->len_precision = 0;
		if (flag->point == true && flag->len_precision >= 0)
			result = ft_strncpy(arg, flag->len_precision);
		else
			result = ft_strdup(arg);
	}
	return (result);
}

void			converter_str(t_flag *flag, t_buffer *buffer)
{
	char	*result;
	char	*arg;
	int		len_arg;

	result = NULL;
	arg = va_arg(*(flag->arg), char *);
	result = check_arg(result, flag, arg);
	len_arg = ft_strlen(result);
	add_padding_str(&result, flag, len_arg);
	add_str(buffer, result);
	free(result);
}
