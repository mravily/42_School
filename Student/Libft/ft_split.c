/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:15:10 by mravily           #+#    #+#             */
/*   Updated: 2019/11/06 17:20:10 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		s_len(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		str_dup(char const *s, char c)
{
	int		i;
	
	i = 0;
	while (s[i])
	return (cmpt_c);
}

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
	printf("cmpt_w = %d\n", cmpt_w);
	return (cmpt_w);
}

char			**ft_split(char const *s, char c)
{
	int 	i;
	int		len_str;
	int		nbr_word;
	char	**str;

	i = 0;
	nbr_word = count_word(s, c);
	len_str = (s_len(s) - count_char(s, c)); // len_str = 20
	if (!(str = (char **)malloc(sizeof(char) * nbr_word)))
		return (NULL);
	while (i < nbr_word)
	{
		s[]
	}
	
	
int main(void)
{
	//char **tab;
	char const s[] = {"*bonjour*coucou*arigato*"};
	count_char(s, '*');
	count_word(s, '*');
	ft_split(s, '*');
	//tab = ft_split("*bonjour*coucou*arigato*", "*");
	//int i;
	//i = 0;
	//while (tab[i])
	/*
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%d\n", i);
	*/
}
