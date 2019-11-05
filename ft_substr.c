/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:46:55 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 20:46:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int ft_slen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*sub;
	unsigned int 	i;
	unsigned int	j;

	i = start;
	j = 0;
	sub = NULL;
	if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}


#include <stdio.h>
int		main(void)
{
	const char s[] = {"substr copie cette partie de la string dans une autre chaine allouer avec malloc"};
	puts(ft_substr(s,15,0));
}