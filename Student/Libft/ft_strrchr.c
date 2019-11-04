/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:37:45 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 17:51:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	tmp = (char *)s;
	while (tmp[j])
		j++;
	i = j;
	while (i > 0)
	{
		if (tmp[i] == c)
			return (&tmp[i]);
		i--;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	const char s[] = {"It's a const string for test function"};

	puts(ft_strrchr(s,'r'));
}
