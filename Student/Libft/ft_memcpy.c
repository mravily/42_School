/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:06:10 by mravily           #+#    #+#             */
/*   Updated: 2019/11/25 17:11:52 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!dst || !src || (dst == src))
		return (dst);
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (n--)
		tmp1[n] = tmp2[n];
	return (dst);
}
