/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 10:41:35 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 16:02:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

char	*ft_strncpy(char *src, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = NULL;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= len)
		dest[i++] = '\0';
	return (dest);
}
