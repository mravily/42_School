/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:59:34 by mravily           #+#    #+#             */
/*   Updated: 2019/11/14 10:37:32 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && needle[j])
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
		return ((char*)haystack + (i - j));
	else
		return (NULL);
}
