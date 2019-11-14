#include <stdio.h>
int		main(void)
{
	char **tab;
	//char const s[] = {"*bonjour*coucou*arigato*"};
	const char	*s = "                  olol";
	//const char	*s = "olol                  ";
	tab = ft_split(s, ' ');
	int i;
	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
		i++;
	printf("i = %d\n", i);
}


/* -------> TEST PHASE <----------------------- */
/*
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}
*/
// #include <stdio.h>

// int		main(void)
// {
// 		char **tab;
// 	//char const s[] = {"*bonjour*coucou*arigato*"};
// 	const char	*s = "                  olo l";
// 	//const char	*s = "olol                  ";
// 	printf("La phrase : [%s]\n", s);
// 	tab = ft_split(s, ' ');
// 	int i;
// 	i = 0;
// 	while (tab[i])
// 		printf("%s\n", tab[i++]);
// 		i++;
// 	printf("i = %d\n", i);
// }