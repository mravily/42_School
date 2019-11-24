/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:35:47 by mravily           #+#    #+#             */
/*   Updated: 2019/11/23 18:35:55 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	size_t			value[2];
	int				ret;
	static char 	*rest;
	int				find;
	
	find = TRUE;
	value[0] = 0;
	value[1] = 0;
	printf("1_rest = %s\n", rest);
	while ((ret = read(fd, buf , BUFFER_SIZE)) > 0)
	{
		printf("2_rest = %s\n", rest);
		buf[ret] = '\0';
		while (buf[value[0]])
		{
			if (find == TRUE && buf[value[0]] && buf[value[0]] != '\n')
			{
				find = FALSE;
				rest = &(buf[value[0]]);
			}
			if (find == FALSE && buf[value[0]] == '\n')
			{
				*line = ft_strdup(rest);
				free(rest);
				value[1]++;
				find = TRUE;
				return (1);
			}
			value[0]++;
		}
		printf("rest = %s\n", rest);
		printf("line = %s\n", *line);
		
	}
	return (ret);
}