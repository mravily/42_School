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
	int		i;

	i = 0;
	while (buf[i])
	{
		printf("buf[%d] = %c\n", i, buf[i]);
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*rest;
	int				ret;
	int				i;
	char			*tmp;
	
	//ret = 1;
	rest = NULL;
	if (fd < 0 || !line)
		return (-1);
	while (ret = read(fd, buf, BUFFER_SIZE) > 0)
	{
		//printf("w_ret = %d\n", ret);
		rest = ft_strjoin(rest, buf);			// ABCDEFGHIJ\nKLMNO
		i = check_backslash_n(buf);
		printf("i = %d | rest = %s\n", i, rest);
		if (i > 0)
		{
			puts("ENTER CONDITION\n");
			printf("rest = %s | i = %d\n", i, rest);
			rest[i] = '\0';
			*line = ft_strdup(rest);			// ABCDEFGHIJ\0
			printf("i = %d | line = %s\n", i, *line);
			tmp = ft_strdup(rest + (i + 1));		// KLMNO\0
			printf("tmp = %s", tmp);
			free(rest);							// rest = NULL;
			rest = tmp;							// rest = KLMNO\0
			printf("rest = %c", rest);
			return (1);
		}
	}
	*line = ft_strdup(rest);
	free(rest);
	rest = NULL;
	return (ret);
}

int        main(void)
{
    int res;
    char *line;
    int fd;

	line = NULL;
    fd = open("test.txt", O_RDONLY);
	printf("open = %d\n", fd);
   	res = get_next_line(fd, &line);
    ("%d | %s\n", res, line);
    free(line);
    close(fd);
    return (0);
}