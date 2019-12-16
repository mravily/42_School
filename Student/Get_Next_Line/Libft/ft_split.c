/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:15:10 by mravily           #+#    #+#             */
/*   Updated: 2019/11/21 09:54:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char const *s, char c)
{
	int i;
	int nbr_w;

	i = 0;
	nbr_w = 1;
	if (s[0] == '\0')
		return (0);
	if (s[0] == c)
		nbr_w = 0;
	while (s[i])
	{
		if (s[i] == c)
			if (s[i + 1] != '\0' && s[i + 1] != c)
				nbr_w++;
		i++;
	}
	return (nbr_w);
}

static char		**ft_tab_alloc(char **tab, char c, char const *str)
{
	size_t	nb_word;
	int		value[3];
	char	find;

	find = 1;
	value[2] = 0;
	nb_word = 0;
	while (str[value[2]] != '\0')
	{
		if (find == 1 && str[value[2]] != '\0' && str[value[2]] != c)
		{
			find = 0;
			value[0] = value[2];
		}
		if (find == 0 && (str[value[2] + 1] == '\0' || str[value[2] + 1] == c))
		{
			find = 1;
			value[1] = value[2] + 1;
			tab[nb_word] = ft_substr(str, value[0], value[1] - value[0]);
			nb_word++;
		}
		value[2]++;
	}
	tab[nb_word] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbr_word;

	if (!s)
		return (NULL);
	nbr_word = count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbr_word + 1))))
		return (NULL);
	if (!(ft_tab_alloc(tab, c, s)))
		return (NULL);
	return (tab);
}
