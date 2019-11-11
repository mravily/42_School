/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:18:49 by mravily           #+#    #+#             */
/*   Updated: 2019/10/31 17:18:49 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char	*tmp1;
	const char *tmp2;

	tmp1 = dst;
	tmp2 = src;
	if (dst > src)
		ft_memcpy(dst, src, size);
	else if (dst != src)
	{
		while (size--)
		*tmp1++ = *tmp2++;
	}
	return (dst);
}
