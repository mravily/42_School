#include "get_next_line.h"

static size_t	ft_strlen_backslash(char *buf)
{
	size_t		i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	static char			*rest;
	int				i;
	char			*tmp;

	ret = 1;
	rest = NULL;
	if (fd < 0 || !line)
		return (-1);
	printf("ft_strlen = %d\n", ft_strlen_backslash(buf));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		rest =  ft_strjoin(rest, buf);
		i = ft_strlen_backslash(rest);
		if (i >= 0)
		{
			rest[i] = '\0';
			*line = ft_strdup(rest);
			tmp = ft_strdup(rest + i + 1);
			free(rest);
			rest = tmp;
			return (1);
		}
	}
	*line =  ft_strdup(rest);
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
    //("%d | %s\n", res, line);
    free(line);
    close(fd);
    return (0);
}