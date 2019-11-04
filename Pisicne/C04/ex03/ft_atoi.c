/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:43:57 by mravily           #+#    #+#             */
/*   Updated: 2019/10/10 00:06:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int cmpt;
	int res;

	i = 0;
	cmpt = 0;
	res = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cmpt++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 +(str[i] - '0');
		i++;
	}
	if (cmpt % 2 == 0)
		return (res);
	else 
		return (-res);
}


#include <stdio.h>
int		main(void)
{
	char str[] = {"	   ---+--+1234ab567"};

	printf("%d",ft_atoi(str));
}