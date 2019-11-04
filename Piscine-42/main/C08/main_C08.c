///////////////////////////////////////////////////////
////////////// C08 ex01  ft_boolean //////////////////
/////////////////////////////////////////////////////

#include "ft_boolean.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}

///////////////////////////////////////////////////////
///////////// C08 ex04  ft_strs_to_tab ///////////////
/////////////////////////////////////////////////////

int							main(int argc, char **argv)
{
	ft_strs_to_tab(argc, argv);
}