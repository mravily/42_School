/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:11:56 by marvin            #+#    #+#             */
/*   Updated: 2019/11/04 19:11:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	unsigned char alnum;

	alnum = c;
	if ((alnum >= 'a' && alnum <= 'z') || (alnum >= 'A' && alnum <= 'Z') ||
		(alnum >= '0' && alnum <= '9'))
		return (1);
	return (0);
}
