///////////////////////////////////////////////////////
///////////////// C09 ex02  ft_split /////////////////
/////////////////////////////////////////////////////

#include <stdio.h>
int main(void)
{
	char **tab;
	tab = ft_split("*&*&*&*&*&bonjour*&*&*&*&coucou*&*&*&*&arigato*&*&*&*&*&*", "");
	int i;
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%d\n", i);
}