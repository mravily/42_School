/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:46:00 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 16:01:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_c(char p_c)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * 2);
	if (dup == NULL)
		return (NULL);
	dup[0] = p_c;
	dup[1] = '\0';
	return (dup);
}
