/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:18:49 by mravily           #+#    #+#             */
/*   Updated: 2019/11/21 18:01:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_c;
	unsigned char	*dst_c;

	src_c = (unsigned char *)src;
	dst_c = (unsigned char *)dst;
	if (dst_c > src_c)
		ft_memcpy(dst, src, len);
	else if (dst != src)
		while (len--)
			*dst_c++ = *src_c++;
	return (dst);
}
