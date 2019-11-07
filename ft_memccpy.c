/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:14:02 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 12:47:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned i;
	unsigned char *tmp1;
	unsigned char *tmp2;

	i = 0;
	tmp1 = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == (unsigned char)c)
			return ((void *)&tmp1[i + 1]);
		i++;
	}
	return (NULL);
}
