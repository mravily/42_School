/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:35:35 by mravily           #+#    #+#             */
/*   Updated: 2019/09/15 23:22:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rush02.h"

char			**ft_split(char *str, char *charset)
{
	int		i;
	int		countw;
	char	**split;

	i = 0;
	countw = ft_countwords(str, charset);
	if (!(split = (char **)malloc(sizeof(char *) * (countw + 1))))
		return (NULL);
	while (i < countw)
	{
		if (!(split[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (NULL);
		i++;
	}
	if (countw > 0)
		split = putword(str, charset, split, countw);
	if (!(split[countw] = (char *)malloc(sizeof(char))))
		return (NULL);
	split[countw] = NULL;
	return (split);
}

char			**putword(char *str, char *charset, char **split, int countw)
{
	int i;
	int count;
	int j;

	count = 0;
	i = 0;
	while (str[i] && count < countw)
	{
		j = 0;
		while (is_in_charset(str[i], charset) == 1 && str[i] != 0)
			i++;
		while (is_in_charset(str[i], charset) == 0 && str[i] != 0)
		{
			split[count][j] = str[i];
			j++;
			i++;
		}
		split[count][j] = '\0';
		count++;
	}
	return (split);
}

int				is_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int				ft_countwords(char *str, char *charset)
{
	int i;
	int count;

	count = 1;
	i = 0;
	if (str[0] == '\0')
		return (0);
	if (is_in_charset(str[0], charset))
		count = 0;
	while (str[i])
	{
		if (is_in_charset(str[i], charset))
			if (str[i + 1] != 0 && is_in_charset(str[i + 1], charset) == 0)
				count++;
		i++;
	}
	return (count);
}

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
