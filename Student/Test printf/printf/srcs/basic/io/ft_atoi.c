/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:47:17 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/23 14:25:22 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *p_str)
{
	int	result;
	int	index;
	int	sign;

	if (p_str == NULL)
		return (0);
	result = 0;
	index = 0;
	sign = 1;
	if (p_str[index] == '+')
		index++;
	else if (p_str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	while (p_str[index] != '\0' && (p_str[index] >= '0' && p_str[index] <= '9'))
	{
		result = (result * 10) + (p_str[index] - 48);
		index++;
	}
	return (result * sign);
}
