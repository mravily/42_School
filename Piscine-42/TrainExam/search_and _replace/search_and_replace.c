/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:33:00 by mravily           #+#    #+#             */
/*   Updated: 2019/09/19 20:21:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	search_and_replace(char *str, char *search, char *replace)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == search[j])
			str[i] = replace[j];
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (ft_strlen(argv[2]) > 1 && ft_strlen(argv[3]) > 1 && argc > 3)
	{
		ft_putchar('\n');
		return (0);
	}
	search_and_replace(argv[1], argv[2], argv[3]);
}