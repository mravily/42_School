#include <stdio.h>

int		sommeTableau(int tab[], int size_tab)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (i < size_tab)
	{
		res += tab[i];
		i++;
	}
	return (res);
}

double		moyenneTableau(int tab[], int size_tab)
{
	double	res;
	int		i;

	res = 0;
	i = 0;
	while (i < size_tab)
	{
		res += tab[i];
		i++;
	}
	res /= size_tab;
	return (res);
}

void		copie(int tab_1[], int tab_2[], int size_tab)
{
	int		i;

	i = 0;
	while (i < size_tab)
	{
		tab_2[i] = tab_1[i];
		i++;
	}
	i = 0;
	while (i < size_tab)
	{
		printf("Tab_cpy[%d] = %d\n", i, tab_2[i]);
		i++;
	}
	puts("\n");
}

void		maximumTableau(int tab[], int size_tab, int max_value)
{
	int		i;

	i = 0;
	while (i < size_tab)
	{
		if (tab[i] > max_value)
			tab[i] = 0;
		i++;
	}
	i = 0;
	while (i < size_tab)
	{
		printf("Tab_max[%d] = %d\n", i, tab[i]);
		i++;
	}
	puts("\n");
}

void		ordonnerTableau(int tab[], int size_tab)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size_tab)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		if (tab[i] < tab[i + 1])
			i++;
	}
	i = 0;
	while (i < size_tab)
	{
		printf("Tab_max[%d] = %d\n", i, tab[i]);
		i++;
	}
	puts("\n");
}

int		main(void)
{
	int		tab_ent[4] = {10, 505, 23, 8};
	int		tab_cpy[4];

	printf("%d\n",sommeTableau(tab_ent, 4));
	printf("%f\n",moyenneTableau(tab_ent, 4));
	copie(tab_ent, tab_cpy, 4);
	//maximumTableau(tab_ent, 4, 10);
	ordonnerTableau(tab_ent, 4);
}
