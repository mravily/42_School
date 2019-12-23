/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:48:36 by mravily           #+#    #+#             */
/*   Updated: 2019/12/14 20:03:11 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_atoi_index(const char *str)
{
	int i;
	int num;

	//printf("str = %s\n", str);
	if (!str)
		return (0);
	i = 0;
	num = 0;
	while (!(str[i] && (str[i] == 'c' || str[i] == 's' || str[i] == 'p'
	|| str[i] == 'd' || str[i] == 'i' || str[i] == 'x' || str[i] == 'X'
	|| (str[i] >= '0' && str[i] <= '9'))))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		num = (str[i++] - '0') + num * 10;
	//printf("atoi_i = %d\n", i);
	return (num);
}
/*
int	ft_atoi(const char *str, t_tool_box *t_box)
{
	int i;
	int num;
	int sign;

	if (!str)
		return (0);
	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || (str[i] > 8 && str[i] < 14)))
		i++;
	if (t_box->pad_dir == RIGHT)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] > 47 && str[i] < 58))
		num = (str[i++] - 48) + num * 10;
	return (num * sign);
}
*/
