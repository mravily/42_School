/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:39:13 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 16:03:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t p_len)
{
	char		*new;
	size_t		i;

	new = (char *)malloc(sizeof(char) * (p_len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < p_len)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
