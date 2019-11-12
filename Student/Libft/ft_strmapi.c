/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:08:13 by mravily           #+#    #+#             */
/*   Updated: 2019/11/12 06:08:13 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	unsigned int len_s;
	char *map;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (!(map = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	while (i < len_s)
	{
		map[i] = (*f)(i, s[i]);
		i++;
	}
	return (map);
}
