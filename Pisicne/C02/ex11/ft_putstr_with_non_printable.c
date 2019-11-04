#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_printable(unsigned char c)
{
	return (c >= 32 && c <= 126);
}

char hexa(unsigned char c)
{
	if (c < 10)
		return ('0' + c);
	return ('a' + (c - 10));
}

void print_hexa(char c)
{
	unsigned char a;

	a = (unsigned)c;
	ft_putchar('\\');
	ft_putchar(hexa(a / 16));
	ft_putchar(hexa(a % 16));
}

void ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_printable(str[i]))
			ft_putchar(str[i]);
		else
			print_hexa(str[i]);
		i++;
}
}


#include <stdio.h>
int		main(void)
{
	print_hexa('\n');
}