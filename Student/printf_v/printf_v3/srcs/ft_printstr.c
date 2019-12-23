/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 01:00:19 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 10:21:52 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_strdup(char *s)
{
	size_t	i;
	size_t	len_s;
	char	*dup;

	len_s = ft_strlen(s);
	if (!(dup = (char *)malloc(sizeof(char) * (len_s + 1))))
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char			*ft_printstr(char *str)
{
	char	*ret;

	if (str == NULL)
	{
		if (!(ret = (char *)malloc(sizeof(char) * 7)))
			return (NULL);
		ret[0] = '(';
		ret[1] = 'n';
		ret[2] = 'u';
		ret[3] = 'l';
		ret[4] = 'l';
		ret[5] = ')';
		ret[6] = '\0';
		return (ret);
	}
	else
	{
		ret = ft_strdup(str);
		return (ret);
	}
}
