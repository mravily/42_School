#include <stdio.h>
int		main(void)
{
	char **tab;
	char const s[] = {"*bonjour*coucou*arigato*"};
	//const char	*s = "                  olol";
	tab = ft_split(s, '*');
	int i;
	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
		i++;
}