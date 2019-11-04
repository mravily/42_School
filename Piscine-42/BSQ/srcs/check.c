/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:50:11 by jmercier          #+#    #+#             */
/*   Updated: 2019/09/18 23:43:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*stread(char *map)
{
	char	c;
	int		i;
	char	*len;
	int		fd;

	i = 0;
	len = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, &c, 1) == 1)
		i++;
	if (!(len = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	close(fd);
	i = 0;
	fd = open(map, O_RDONLY);
	while (read(fd, &c, 1) == 1)
	{
		len[i] = c;
		i++;
	}
	len[i] = '\0';
	close(fd);
	return (len);
}

char	**ft_mapparser(char *len)
{
	char **lines;

	lines = ft_split(len, "\n");
	free(len);
	return (lines);
}
