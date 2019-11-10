/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 10:55:11 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 14:01:21 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	while (src[cpt] != '\0' && i + cpt < size - 1 && size != 0)
	{
		dest[i + cpt] = src[cpt];
		cpt++;
	}
	if (size != 0)
		dest[i + cpt] = '\0';
	if (size < i)
		return (j + size);
	else
		return (j + i);
}
