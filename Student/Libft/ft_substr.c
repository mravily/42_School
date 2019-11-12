/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:46:55 by mravily           #+#    #+#             */
/*   Updated: 2019/11/12 08:55:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	j;

	j = 0;
	if (!s)
		return (NULL);
	sub = NULL;
	if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (j < len)
	{
		sub[j] = s[start];
		start++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
