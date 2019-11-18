void	salut(int *test)
{
	(*test) = 18;
}

int		main(void)
{
	int		i;
	int		*b;

	i = 0;
	b = &i;
	printf("i = %d\n", i);
	//salut(&i);
	//printf("i = %d\n", i);
	printf("b = %d\n", b);
}