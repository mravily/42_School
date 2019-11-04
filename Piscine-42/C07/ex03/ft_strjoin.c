/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:30:17 by mravily           #+#    #+#             */
/*   Updated: 2019/09/13 20:04:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_count_size(char **strs, char *sep, int size)
{
	int		i;
	int		sizetab;
	char	*tab;

	i = 0;
	sizetab = 0;
	while (i < size)
	{
		sizetab = sizetab + (ft_strlen(strs[i]) + ft_strlen(sep));
		i++;
	}
	sizetab = sizetab - ft_strlen(sep);
	tab = NULL;
	tab = malloc(sizeof(char) * (sizetab + 1));
	if (tab == NULL)
		return (0);
	return (tab);
}

char	*ft_loop_cat(char **strs, char *sep, int size, char *tab)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (i < size)
	{
		tab[k++] = strs[i][j++];
		if (strs[i][j] == '\0')
		{
			l = 0;
			while (i < size - 1)
				tab[k++] = sep[l++];
			j = 0;
			i++;
		}
	}
	tab[k] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;

	if (size == 0)
	{
		tab = malloc(sizeof(char) * 1);
		tab[0] = '\0';
		return (tab);
	}
	tab = ft_count_size(strs, sep, size);
	ft_loop_cat(strs, sep, size, tab);
	return (tab);
}

int		main(int argc, char **argv)
{
	printf("return = %s", ft_strjoin(argc, argv, "[...]"));
}
