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
		return ((char *)haystack + (i - j));
}


#include <stdio.h>
#include <string.h>
int		main(void)
{
	char	*s1 = "see FF your FF return FF now FF";
	char	*s2 = "FF";

	size_t	max = strlen(s1);
	char	*i1 = strnstr(s1, s2, max);
	char	*i2 = ft_strnstr(s1, s2, max);

	if (i1 == i2)
		printf("TEST_SUCCESS\n");
	else 
		printf("TEST_FAILED\n");

	printf("Diff :\n");
	printf("strnstr = %s\n", strnstr(s1, s2, max));
	printf("ft_strnstr = %s\n", ft_strnstr(s1, s2, max));
}