void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main(void)
{
	char	*dest;

	size_t	i1;
	size_t	i2;
	i1 = strlcat(dest, "lorem ipsum dolor sit amet", 5);
	i2 = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
	memset(dest, 'r', 15);
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, dest, 15);
	puts("\n");
	if (i1 == 12)
	{
		puts("TEST_SUCESS");
		puts("\n");
	}
	else
	{
		puts("TEST_FAILED");
		puts("\n");
	}
	puts("Diff :");
	printf("strlcat = %zu\n", i1);
	printf("ft_strlcat = %zu\n", i2);
}