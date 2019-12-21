/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:35:49 by mravily           #+#    #+#             */
/*   Updated: 2019/12/21 19:19:27 by mravily          ###   ########.fr       */
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

void converter_str(t_flag *flag, t_buffer *buffer)
{
	char	*result;
	char	*ret;
	int		len_arg;

	result = ft_strdup(va_arg(*(flag->arg), char *));
	len_arg = ft_strlen(result);
	//printf("len_arg = %d\n", len_arg);
	//printf("len_prec = %d\n", flag->len_precision);
	//printf("len_padd = %d\n", flag->len_padding);
	if (result == NULL)
	{
		if (!(result = (char*)malloc(sizeof(char) * 7)))
		return ;
		result[0] = '(';
		result[1] = 'n';
		result[2] = 'u';
		result[3] = 'l';
		result[4] = 'l';
		result[5] = ')';
		result[6] = '\0';
		len_arg = ft_strlen(result);
	}
	//printf("len_arg = %d\n", len_arg);
	if (len_arg > flag->len_precision && flag->len_precision != -1)
	{
		result = cpynchar(result, flag->len_precision);
		len_arg = ft_strlen(result);
	}
	if (len_arg < flag->len_padding)
	{
		add_padding(&result, flag->zero, flag->len_padding - len_arg, flag->padding_direction);
	}
	//printf("result = %s\n", result);
	add_str(buffer, result);
	free(result);
}
