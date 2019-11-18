#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE];
	int				test;

	if (fd < 0 || !line)
		return (-1);
	while(test = read(fd, buf, BUFFER_SIZE)) // BUFFER SIZE = 32
	{
		printf("buf = %s\n", buf);
	}  
	buf[test] = '\0';
	
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
    printf("%d | %s\n", res, line);
    free(*line);
    close(fd);
    return (0);
}