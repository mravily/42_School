/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:14:57 by mravily           #+#    #+#             */
/*   Updated: 2019/11/04 20:14:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	int				i;
	unsigned char	*mem;

	if (!(mem = (char *)malloc(size * (sizeof(char)))))
		return (NULL);
	while (i < size)
	{
		mem[i] = '0';
		i++;
	}
	return ((void *)mem);
	
}