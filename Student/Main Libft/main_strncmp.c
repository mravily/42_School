#include <stdio.h>
#include <string.h>
int		main(void)
{
	char	*s1 = "\x12\xff\x65\x12\xbd\xad";
	char	*s2 = "\12\x02";
	size_t	size = 6;
	int		i1 = ((strncmp(s1, s2, size) > 0) ? 1 : ((strncmp(s1, s2, size) < 0) ? -1 : 0));
	int		i2 = ((ft_strncmp(s1, s2, size) > 0) ? 1 : ((ft_strncmp(s1, s2, size) < 0) ? -1 : 0));

	if (i1 == i2)
		puts("TEST_SUCCESS\n");
	else
		puts("TEST_FAILED\n");

	puts("Diffs :\n");
	printf("strncmp = %d\n", strncmp(s1, s2, size));
	printf("ft_strncmp = %d\n", ft_strncmp(s1, s2, size));
}