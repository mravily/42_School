#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int			main(void)
{
	int		fd1 = open("a", O_RDONLY);
	int		fd2 = open("lol", O_RDONLY);
	int		fd3 = open("b", O_RDONLY);
	int		fd4 = 42;
	int		fd5 = open("test", O_RDONLY);
	int		ret;
	char	*line;

	ret = get_next_line(fd1, &line);
	printf("%d | %s\n", ret, line);
	system("leaks a.out| grep 'total leaked bytes.'");
	free(line);
	line = NULL;
	ret = get_next_line(fd2, &line);
	printf("%d | %s\n", ret, line);
	system("leaks a.out| grep 'total leaked bytes.'");
	free(line);
	line = NULL;
	ret = get_next_line(fd3, &line);
	printf("%d | %s\n", ret, line);
	system("leaks a.out| grep 'total leaked bytes.'");
	free(line);
	line = NULL;
	ret = get_next_line(fd4, &line);
	printf("%d | %s\n", ret, line);
	system("leaks a.out| grep 'total leaked bytes.'");
	free(line);
	line = NULL;
	ret = get_next_line(fd5, &line);
	printf("%d | %s\n", ret, line);
	system("leaks a.out| grep 'total leaked bytes.'");
	free(line);
	line = NULL;
}
