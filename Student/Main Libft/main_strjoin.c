#include <stdio.h>
int		main(void)
{
	char	*s1 = "where is my ";
	char	*s2 = "malloc ???";
	char	*s3 = "where is my malloc ???";

	char *res = ft_strjoin(s1, s2);
	if (res == s3)
		printf("TEST_SUCCESS\n");
	else
		printf("TEST_FAILED\n");

	puts("Diff :\n");
	printf("strjoin = %s\n", s3);
	printf("ft_strjoin = %s\n", ft_strjoin(s1, s2));
}