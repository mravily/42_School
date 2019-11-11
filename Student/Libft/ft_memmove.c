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

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dst || !src)
		return (NULL);
	if (!(tmp = (unsigned char *)malloc(sizeof(char) * n)))
		return (NULL);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dst, tmp, n);
	free (tmp);
	return (dst);
}