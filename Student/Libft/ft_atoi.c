/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:23:00 by mravily           #+#    #+#             */
/*   Updated: 2019/11/21 10:02:30 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		s;
	int		stk;

	stk = 0;
	s = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\v'
		|| *str == '\t' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		stk *= 10;
		stk += *str - '0';
		str++;
	}
	return (stk * s);
}
