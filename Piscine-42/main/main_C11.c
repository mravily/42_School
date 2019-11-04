///////////////////////////////////////////////////////
/////////////// C11 ex04  ft_is_sort /////////////////
/////////////////////////////////////////////////////

int	fonc(int i, int j)
{
	if (i < j)
		return (-1);
	if (i > j)
		return (1);
	return (0);
}

int	main()
{
	int tab[] = {3, 2, 1, 3};

	int (*f)(int, int);

	f = &fonc;
	printf("is sort = %d\n", ft_is_sort(tab, 3, f));
}