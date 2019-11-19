/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:59:01 by mravily           #+#    #+#             */
/*   Updated: 2019/11/19 20:05:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_backslash_n(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1]
	static char		*rest;
	int				ret;
	
}