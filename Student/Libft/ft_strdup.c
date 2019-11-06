/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:12:48 by mravily           #+#    #+#             */
/*   Updated: 2019/11/06 17:02:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dup;

	dup = NULL;
	if (s == NULL)
		return (NULL);
	if (!(dup = (char *)malloc(ft_strlen(s) * sizeof(char) + 1)))
		return (NULL);
	else
		dup = ft_strcpy(dup, s);
	return (dup);
}
