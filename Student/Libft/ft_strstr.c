/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:59:34 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 14:30:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *baystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)baystack);
	while (baystack[i] && needle[j])
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
		return ((char*)baystack + (i - j));
	else
		return (NULL);
}
