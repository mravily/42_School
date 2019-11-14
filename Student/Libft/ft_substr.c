/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:46:55 by mravily           #+#    #+#             */
/*   Updated: 2019/11/14 14:58:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			j;

	if (!s)
		return (ft_strdup(""));
	if (ft_strlen(s) < start)
		len = 0;
	sub = NULL;
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	j = 0;
	while (j < len)
	{
		sub[j] = s[start];
		start++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
