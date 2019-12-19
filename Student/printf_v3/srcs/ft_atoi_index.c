/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:52:07 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 15:02:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_atoi_index(const char *str)
{
	unsigned long long	res;
	unsigned int		sign;
	unsigned int		i;

	res = 0;
	sign = 1;
	i = 0;
	//printf("str = %s\n", str);
	while (*str && (str[0] == ' ' || str[0] == '\n' || str[0] == '\r'
	|| str[0] == '.' || str[0] == '\t' || str[0] == '\v' || str[0] == '\f'))
		str++;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (i > 19 || res >= 9223372036854775808ULL)
		return (sign == 1 ? -1 : 0);
	//printf("res = %d\n", res);
	return (res * sign);
}
