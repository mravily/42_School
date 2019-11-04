/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:37:53 by adbenoit          #+#    #+#             */
/*   Updated: 2019/09/18 23:42:47 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		error(char **lines, int argc)
{
	int i;

	i = 1;
	while (lines[i])
	{
		if (ft_strlen(lines[1]) != ft_strlen(lines[i]))
			return (0);
		else
			i++;
	}
	if (ft_size2(lines) == 0 || ft_strlen(lines[0]) < 4)
		return (0);
	i = ft_strlen(lines[0]);
	while (i > ft_strlen(lines[0]) - 3)
	{
		if ((lines[0][i] == lines[0][i - 1] && i != ft_strlen(lines[0]) - 3)
				|| lines[0][i] < 32 || lines[0][i] > 126)
			return (0);
		else
			i--;
	}
	while (i >= 0)
	{
		if (lines[0][i] < 0 || lines[0][i] > 9)
			return (0);
		else
			i--;
	}
	if (argc < 2)
		return (0);
	return (1);
}
