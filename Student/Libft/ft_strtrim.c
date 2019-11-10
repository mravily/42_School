/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:42:08 by mravily           #+#    #+#             */
/*   Updated: 2019/11/06 14:16:10 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		s_len(char const *s1)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static int		check_char(char c, char const *charset)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (1);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int		find_start(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (check_char(s1[i], set) == 0)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static int		find_end(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		end;

	i = s_len(s1);
	j = 0;
	end = i;
	while (i > 0)
	{
		if (check_char(s1[i], set) == 0)
		{
			return (i);
		}
		i--;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*str;

	i = find_start(s1, set);
	j = find_end(s1, set);
	len = j - i;
	k = 0;
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
