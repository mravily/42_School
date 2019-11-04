/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:59:54 by adbenoit          #+#    #+#             */
/*   Updated: 2019/09/18 23:43:49 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_cmp(char s, char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s != charset[j] && charset[j])
		j++;
	while (charset[i] != '\0')
		i++;
	if (j == i)
		return (1);
	return (0);
}

char	*ft_strcat(char *dest, char src)
{
	unsigned int i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest[i] = 0;
	dest[i] = src;
	i++;
	dest[i] = '\0';
	return (dest);
}

int		ft_size(char *str, char *charset, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		if (ft_cmp(str[i], charset) == 1)
			k++;
		else
			break ;
		i++;
	}
	return (k);
}

int		ft_nbchar(char *str, char *charset)
{
	int i;
	int j;
	int k;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		k = 0;
		while (i > 0 && str[i - 1] != charset[k] && charset[k])
			k++;
		if (ft_cmp(str[i], charset) == 1 &&
				(ft_cmp(str[i - 1], charset) == 0 || i == 0))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		k;
	int		x;
	char	**dest;

	i = -1;
	k = 0;
	if (!(dest = malloc(sizeof(char*) * (ft_nbchar(str, charset) + 1))))
		return (0);
	while (str[++i])
	{
		if (ft_cmp(str[i], charset) == 1 && ft_size(str, charset, i) > 0)
		{
			if (!(dest[k] = malloc(sizeof(char) *
							(ft_size(str, charset, i) + 1))))
				return (0);
			x = i;
			i--;
			while (++i < (ft_size(str, charset, x) + x))
				dest[k] = ft_strcat(dest[k], str[i]);
			k++;
		}
	}
	dest[k] = 0;
	return (dest);
}
