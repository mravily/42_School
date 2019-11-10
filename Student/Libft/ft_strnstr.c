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
	if (needle == NULL)
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		while (needle[j])
		{
			if (needle[j] != haystack[i])
				j = 0;
			j++;
		}
		i++;
	}
	if (haystack[i] == '\0')
		return (NULL);
	else
		return ((char *)haystack);
}
