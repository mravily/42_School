/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:42:08 by mravily           #+#    #+#             */
/*   Updated: 2019/11/05 17:18:42 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		compt_char(char const *s1, char const *set)
{
	int i;
	int j;
	int cmpt;

	i = 0;
	cmpt = 0;
	if (s1[i] == '\0')
		cmpt++;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				cmpt++;
			j++;
		}
		i++;
	}
	return (cmpt);
}

static int		s_len(char const *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	int		len_str;

	len_str = (s_len(s1) - compt_char(s1, set));

	printf("len_str = %d\n", len_str);

	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * len_str + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				j++;
		}
		str[i] = s1[i];
		i++;
	}
	return (str);
}

int		main(void)
{
	const char	s1[] = {"Creztztge sztrrzignzg erstg lgirszizbrlze"};
	char		set[] = {"zrg"};

	puts(ft_strtrim(s1, set));
}
