/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:36:02 by mravily           #+#    #+#             */
/*   Updated: 2019/11/02 14:36:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
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
	while (src[cpt] != '\0' && i + cpt < n - 1 && n != 0)
	{
		dest[i + cpt] = src[cpt];
		cpt++;
	}
	if (n != 0)
		dest[i + cpt] = '\0';
	if (n < i)
		return (j + n);
	else
		return (j + i);
}
