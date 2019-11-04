/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:52:07 by abenoit           #+#    #+#             */
/*   Updated: 2019/09/18 23:43:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char			**ft_mapparser(char *len)
{
	char **lines;

	lines = ft_split(len, "\n");
	free(len);
	return (lines);
}
