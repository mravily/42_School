/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_to_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:10:04 by mravily           #+#    #+#             */
/*   Updated: 2019/09/15 23:19:31 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rush02.h"

int		main(int argc, char **argv)
{
	int		file;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*dico;
	int		i;

	file = open("EN.txt", O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	ret = read(file, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (!(dico = ((char*)malloc(sizeof(char) * (ret)))))
		return (0);
	i = -1;
	while (dico != '\0' && buf[++i])
		dico[i] = buf[i];
	dico[i] = 0;
	if (close(file) == -1)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
}
