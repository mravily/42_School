/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:46:55 by mravily           #+#    #+#             */
/*   Updated: 2019/11/10 17:05:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	j;

	j = 0;
	sub = NULL;
	if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (j <= len)
	{
		sub[j] = s[start];
		start++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

#include <stdio.h>
int		main(void)
{
	char	*str = "i just want this part #############";
	size_t	size = 20;
	char	*i1 = ft_substr(str, 5, size);

	printf("%s", i1);
}
