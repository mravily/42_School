#include <stdio.h>
int		main(void)
{
	char	*s1 = "where is my ";
	char	*s2 = "malloc ???";
	char	*s3 = "where is my malloc ???";

	char *res = ft_strjoin(s1, s2);

	if (res == s3)
		printf("TEST_SUCCESS");
	else
		printf("TEST_FAILED");