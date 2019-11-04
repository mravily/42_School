/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:47:05 by mravily           #+#    #+#             */
/*   Updated: 2019/09/18 22:10:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_char(char c, char *charset)
{
	int i;

	i = 0;
	if (c == '\0')
		return (TRUE);
	while (charset[i])
	{
		if (c == charset[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int		in_word(char *str, char *charset)
{
	int i;
	int countw;

	i = 0;
	countw = 1;
	if (str[0] == '\0')
		return (0);
	if (check_char(str[0], charset))
		countw = 0;
	while (str[i])
	{
		if (check_char(str[i], charset))
			if (str[i + 1] != '\0' && check_char(str[i + 1], charset) == FALSE)
				countw++;
		i++;
	}
	return (countw);
}

char	**put_word(int nbr_wrd, char **tab, char *str, char *charset)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] && count < nbr_wrd)
	{
		j = 0;
		while (check_char(str[i], charset) == 1 && str[i] != 0)
			i++;
		while (check_char(str[i], charset) == 0 && str[i] != 0)
		{
			tab[count][j] = str[i];
			j++;
			i++;
		}
		tab[count][j] = '\0';
		count++;
	}
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;
	int		nbr_wrd;

	nbr_wrd = in_word(str, charset);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * (nbr_wrd + 1))))
		return (0);
	while (i < nbr_wrd)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (0);
		i++;
	}
	tab[i] = NULL;
	put_word(nbr_wrd, tab, str, charset);
	return (tab);
}
#include <stdio.h>
int main(void)
{
	char **tab;
	tab = ft_split("*&*&*&*&*&bonjour*&*&*&*&coucou*&*&*&*&arigato*&*&*&*&*&*", "&");
	int i;
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%d\n", i);
}
