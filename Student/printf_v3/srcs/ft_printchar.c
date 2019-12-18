/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 01:01:57 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 10:03:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_printchar(int c)
{
	char	*str;

	if (c == '\x00')
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			return (0);
		str[0] = '\x00';
		str[1] = '\0';
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			return (0);
		str[0] = c;
		str[1] = '\0';
	}
	return (str);
}
