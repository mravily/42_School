/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:44:24 by mravily           #+#    #+#             */
/*   Updated: 2019/11/22 19:32:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	void			*mem;

	i = 0;
	if (!count || !size)
		return (ft_strdup(""));
	if (!(mem = malloc(size * count)))
		return (NULL);
	ft_bzero(mem, (count * size));
	return (mem);
}
