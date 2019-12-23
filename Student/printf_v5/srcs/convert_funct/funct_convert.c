/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:50:07 by mravily           #+#    #+#             */
/*   Updated: 2019/12/22 19:03:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		set_funct_convert_tab(char *funct_convert)
{
	int		i;

	i = 0;
	while(i < 127)
	{
		funct_convert[i] = NULL;
		i++;
	}
	funct_convert[0] = (void *)(-1);
	funct_convert['d'] = (void *)(-1);
	funct_convert['i'] = (void *)(-1);
	funct_convert['c'] = (void *)(-1);
	funct_convert['s'] = (void *)(-1);
	funct_convert['p'] = (void *)(-1);
	funct_convert['x'] = (void *)(-1);
	funct_convert['X'] = (void *)(-1);
	funct_convert['p'] = (void *)(-1);
}
