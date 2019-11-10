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
	char	*join;
	int		i;
	int		j;
	int		len_s;

	i = 0;
	j = 0;
	len_s = (ft_slen(s1) + ft_slen(s2));
	join = NULL;
	if (!(join = (char *)malloc(sizeof(char) * len_s)))
		return (NULL);
	while (i < len_s)
	{
		join[i] = s1[i];

		if (s1[i] == '\0')
		{
			while (s2[j])
			{
				join[i] = s2[j];
				i++;
				j++;
			}
		}
		i++;
	}
	join[i] = '\0';
	return (join);
}

#include <stdio.h>
int		main(void)
{
	char	*s1 = "where is my ";
	char	*s2 = "malloc ???";
	char	*s3 = "where is my malloc ???";

	char *res = ft_strjoin(s1, s2);
	if (res == s3)
		printf("TEST_SUCCESS\n");
	else
		printf("TEST_FAILED\n");

	puts("Diff :\n");
	printf("strjoin = %s\n", s3);
	printf("ft_strjoin = %s\n", ft_strjoin(s1, s2));
}
