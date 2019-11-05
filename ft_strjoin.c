/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:53:49 by marvin            #+#    #+#             */
/*   Updated: 2019/11/05 08:53:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_slen(const char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*join;
	unsigned int	i;
	unsigned int	len_s;

	i = 0;
	len_s = (ft_slen(s1) + ft_slen(s2));
	join = NULL;
	if (!(join = (char *)malloc(sizeof(char) * (len_s + 1)))
	while (join[i])
	{
		join[i] = s1[i];
		if (s1[i] == '\0')
		{
			while (s2[j])
			{
				join[i] = s2[j];
			}
		}
	}
	
}


#include <stdio.h>
int		main(void)
{
	const char	s1[] = {"1st part of string "};
	const char	s2[] = {"2nd part of string"};

	puts(ft_strjoin(s1, s2));
}