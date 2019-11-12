/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:18:49 by mravily           #+#    #+#             */
/*   Updated: 2019/11/12 15:37:25 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*srcc;
	unsigned char	*dstc;
	size_t			i;

	i = 0;
	srcc = (unsigned char *)src;
	dstc = (unsigned char *)dst;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (srcc < dstc)
		while (n--)
			*(dstc + n) = *(srcc + n);
	else
		while (i < n)
		{
			*(dstc + i) = *(srcc + i);
			i++;
		}
	return (dst);
}
