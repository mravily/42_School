/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_no_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:15:10 by mravily           #+#    #+#             */
/*   Updated: 2019/11/19 08:24:21 by mravily          ###   ########.fr       */
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

static char		**ft_tab_alloc(char **tab, char c, char *str)
{
	size_t	nb_word;
	int		i;
	char	find;

	find = 1;
	i = 0;
	nb_word = 0;
	while (str[i] != '\0')
	{
		if (find == 1 && str[i] != '\0' && str[i] != c)
		{
			find = 0;
			tab[nb_word] = &(str[i]);
		}
		if (find == 0 && str[i] == c)
		{
			str[i] = '\0';
			nb_word++;
			find = 1;
		}
		i++;
	}
	tab[nb_word] = NULL;
	return (tab);
}

char			**ft_split_no_malloc(char *s, char c)
{
	char	**tab;
	int		nbr_word;

	if (!s || !c)
		return (NULL);
	nbr_word = count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbr_word + 1))))
		return (NULL);
	if (!(ft_tab_alloc(tab, c, s)))
		return (NULL);
	return (tab);
}
