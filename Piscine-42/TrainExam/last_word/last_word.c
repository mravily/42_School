#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_last_word(char *str)
{
	int i;
	int cpt;
	int len;

	i = 0;
	cpt = 0;
	len = 0;

	while (str[i] && str[i + 1] == ' ' && )
	{
		i++;
		len++;
	}
	while (str[i - 1] >= 33 && str[i - 1] <= 126)
	{
		i--;
		cpt++;
	}
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int main(int argc, char **argv)
{
	(void)argc;
	int i;

	i = 1;

	while (i < argc)
	{
		ft_last_word(argv[i]);
		i++;
	}
}