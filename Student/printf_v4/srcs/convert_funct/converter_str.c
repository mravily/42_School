/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:35:49 by mravily           #+#    #+#             */
/*   Updated: 2019/12/19 20:23:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char			*cpynchar(char *result, int len_prec)
{
	size_t		i;
	char		*new;
	
	if (!(new = (char *)malloc(sizeof(char) * len_prec + 1)))
		return (NULL);
	i = 0;
	while (i < len_prec)
	{
		new[i] = result[i];
		i++;
	}	
	new[i] = '\0';
	return (new);
}

char			*converter_str(t_flag *flag)
{
	char	*result;
	char	*ret;
	int		len_arg;

	result = ft_strdup(va_arg(*(flag->arg), char *));
	len_arg = ft_strlen(result);
	//printf("len_arg = %d\n", len_arg);
	//printf("len_prec = %d\n", flag->len_precision);
	if (result == NULL)
	{
		if (!(ret = (char *)malloc(sizeof(char) * 7)))
			return (NULL);
		ret[0] = '(';
		ret[1] = 'n';
		ret[2] = 'u';
		ret[3] = 'l';
		ret[4] = 'l';
		ret[5] = ')';
		ret[6] = '\0';
		return (ret);
	}
	if (len_arg > flag->len_precision)
	{
		result = cpynchar(result, flag->len_precision);
	}
	else if (len_arg < flag->len_padding)
	{
		ft_padding(&result, flag->zero, flag->len_padding - len_arg, flag->padding_direction);
	}
	return(result);
}
