/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:26:12 by mravily           #+#    #+#             */
/*   Updated: 2019/11/25 17:25:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	if (!s)
		return (NULL);
	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp != (unsigned char)c)
			tmp++;
		else
			return ((void *)tmp);
	}
	return (0);
}
