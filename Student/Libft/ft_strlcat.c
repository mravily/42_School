/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:36:02 by mravily           #+#    #+#             */
/*   Updated: 2019/11/14 12:04:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t len_dest;
	size_t len_src;
	size_t j;
	size_t i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = len_dest;
	j = 0;
	if (n <= len_dest)
		return (len_src + n);
	while (src[j] && (i + 1) < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}
