/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:41:23 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 14:11:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *baystack, const char *needle, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)baystack);
	while (baystack[i])
	{
		while (baystack[i] == needle[j] && j < n)
		{
			if (baystack[i] != needle[j])
				j = 0;
			j++;
		}
		i++;
	}
	if (needle)
	return (NULL);
	else 
		return (NULL);
}

#include <stdio.h>
int		main(void)
{
	const char *baystack = "Foo Bar Baz";
    const char *needle = "Bar";

	puts(ft_strnstr(baystack, needle, 4));
}