/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:19:55 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 16:01:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *p_src, char *p_dest)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_dest == NULL)
		return (NULL);
	while (p_src[i] != '\0')
	{
		p_dest[i] = p_src[i];
		i++;
	}
	p_dest[i] = '\0';
	return (p_dest);
}
