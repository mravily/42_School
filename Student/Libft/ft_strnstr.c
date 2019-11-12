/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:48:07 by mravily           #+#    #+#             */
/*   Updated: 2019/11/12 15:48:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle[j])
			j++;
		else
			j = 0;
		i++;
		if (needle[j] == '\0')
			return ((char *)haystack + (i - j));
	}
	return (0);
}
