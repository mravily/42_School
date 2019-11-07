/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:13:36 by mravily           #+#    #+#             */
/*   Updated: 2019/11/07 14:31:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*f;

	i = 0;
	f = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (f + i);
		i++;
	}
	if (s[i] == c)
		return (f + i);
	return (NULL);
}
