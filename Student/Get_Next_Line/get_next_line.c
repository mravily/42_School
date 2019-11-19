#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	int				test;
	int				i;

	if (fd < 0 || !line)
		return (-1);
	test = read(fd, buf, BUFFER_SIZE);
	buf[test] = '\0';
	printf("test = %d\n", test);
	i = 0;
	while (buf[i])
	{
		printf("%c", buf[i]);
		i++;
	}
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
   // printf("%d | %s\n", res, line);
    free(*line);
    close(fd);
    return (0);
}