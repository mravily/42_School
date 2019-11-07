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
#include <stdio.h>

static	int		count_word(char const *s, char c)
{
	int i;
	int cmpt_w;

	i = 0;
	cmpt_w = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			cmpt_w++;
		i++;
	}
	return (cmpt_w);
}

static int		tab_malloc(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		len_word;

	i = 0;
	j = 0;
	while (j < count_word(s, c))
	{
		len_word = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			len_word++;
			i++;
		}
		if (!(tab[j] = (char *)malloc(sizeof(char) * (len_word + 1))))
			return (NULL);
		j++;
	}
	tab[j][0] = '\0';
	return (1);
}

char			**ft_split(char const *s, char c)
{
	int 	i;
	int 	j;
	int		k;
	int		nbr_word;
	char	**tab;

	i = 0;
	j = 0;
	nbr_word = count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char) * (nbr_word + 1))))
		return (NULL);
	tab_malloc(tab, s, c);
	while (i < nbr_word)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			tab[i][k] = s[j];
			k++;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

int		main(void)
{
	char **tab;
	char const s[] = {"*bonjour*coucou*arigato*"};
	count_word(s, '*');
	tab = ft_split(s, '*');
	int i;
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%d\n", i);
}
