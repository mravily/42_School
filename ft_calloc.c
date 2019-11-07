<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:44:24 by mravily           #+#    #+#             */
/*   Updated: 2019/11/07 14:44:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*mem;

	i = 0;
	if (!(mem = malloc(size * count)))
		return (NULL);
	while (i <= (count * size))
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
=======
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
>>>>>>> 2f0b94d96dbebde8e0c96cfe162370bc48ff3ee1
