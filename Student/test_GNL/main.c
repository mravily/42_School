/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:33:37 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/23 17:12:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*lol;
	int		fd = 0;
	int		ret;

	ret = 1;
	if (ac == 1)
		while (ret == 1)
		{
			ret = get_next_line(0, &lol);
			printf("%s\n", lol);
			free(lol);
			lol = NULL;
		}
	else
	{
		fd = open(av[1] ,O_RDONLY);
		while (ret == 1)
		{
			ret = get_next_line(fd, &lol);
			if (ret == 1)
				printf("%s\n", lol);
			else if (ret == 0)
				printf("%s", lol);
			free(lol);
			lol = NULL;
		}
	}
	close(fd);
}
