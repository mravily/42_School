/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:15:10 by mravily           #+#    #+#             */
/*   Updated: 2019/11/07 11:56:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char const *s, char c)
{
	int i;
	int nbr_w;

	i = 0;
	nbr_w = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			nbr_w++;
		i++;
	}
	return (nbr_w);
}

static char		**put_word(int nbr_word, char **tab, char const *s, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] && count < nbr_word)
	{
		j = 0;
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i] != c)
		{
			tab[count][j] = s[i];
			j++;
			i++;
		}
		tab[count][j] = '\0';
		count++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;
	int		len_word;
	int		nbr_word;

	nbr_word = count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * nbr_word)))
		return (NULL);
	i = 0;
	k = 0;
	len_word = 0;
	while (k < nbr_word)
	{
		while (s[++i] == c)
		while (s[i++] != c)
			len_word++;
		if (!(tab[k] = (char *)malloc(sizeof(char) * (len_word + 1))))
			return (NULL);
		k++;
	}
	tab[k] = NULL;
	put_word(nbr_word, tab, s, c);
	return (tab);
}
