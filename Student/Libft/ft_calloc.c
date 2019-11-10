/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:44:24 by mravily           #+#    #+#             */
/*   Updated: 2019/11/10 11:18:57 by marvin           ###   ########.fr       */
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
