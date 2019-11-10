/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:41:23 by mravily           #+#    #+#             */
/*   Updated: 2019/11/07 14:43:25 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
		if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && needle[j] && i < n)
	{
		while (haystack[i] == needle[j])
		{
			if (haystack[i] != needle[j])
				j = 0;
			j++;
		}
		i++;
	}
	if (needle[j] == '\0')
		return ((char*)haystack + (i - j) - 1);
	else
		return (NULL);
}
