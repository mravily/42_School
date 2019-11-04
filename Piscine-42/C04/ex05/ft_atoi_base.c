/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:26:07 by mravily           #+#    #+#             */
/*   Updated: 2019/09/19 01:42:58 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		checkbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		if ((base[i] == ' ') || (base[i] == '\t') || (base[i] == '\n')
		|| (base[i] == '\r') || (base[i] == '\v') || (base[i] == '\f'))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int res;
	int sign;
	int j;

	res = 0;
	sign = 1;
	j = -1;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
	|| (*str == '\r') || (*str == '\v') || (*str == '\f'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (base[++j])
		if (*str == base[j] && checkbase(base))
		{
			res = res * checkbase(base) + j;
			j = -1;
			str++;
		}
	return (sign > 0 ? res : -res);
}

int main()
{
	printf("%d\n", ft_atoi_base("", "0123456789QWERTY"));
}