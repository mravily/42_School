/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:33:38 by mravily           #+#    #+#             */
/*   Updated: 2019/11/07 14:33:38 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int		i;
	char				*d;

	d = (char *)s;
	i = ft_strlen(s);
	while (i <= 0)
	{
		if (s[i] == (char)c)
			return (d + i);
		i--;
	}
	return (NULL);
}

int		main(void)
{
	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
	char *d1 = strrchr(src, ' ');
	char *d2 = ft_strrchr(src, ' ');

	if (d1 == d2)
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);

	char *src = "abbbbbbbb";
	char *d1 = strrchr(src, 'a');
	char *d2 = ft_strrchr(src, 'a');

	if (d1 == d2)
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);

		char *src = "the cake is a lie !\0I'm hidden lol\r\n";
	char *d1 = strrchr(src, ' ');
	char *d2 = ft_strrchr(src, ' ');

	if (d1 == d2)
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);
	
	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char *d1 = strrchr(src, '\0');
	char *d2 = ft_strrchr(src, '\0');

	if (d1 == d2)
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);
}