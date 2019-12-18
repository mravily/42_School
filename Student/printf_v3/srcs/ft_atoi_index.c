/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:52:07 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 00:53:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_atoi_index(const char *str)
{
	size_t		i;
	int			res;

	i = 0;
	res = 0;
	//PRINTPOS;
	//printf("str = %s\n", str);
	while (ft_isdigit(str[i]) == 1)
		res = (str[i++] - '0') + res * 10;
	return (res);
}
