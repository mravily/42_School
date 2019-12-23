/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:24:31 by mravily           #+#    #+#             */
/*   Updated: 2019/12/22 19:15:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		set_convert_flag_tab(char **convert_flag)
{
	int		i;

	i = 0;
	while (i < 127)
	{
		convert_flag[i] = NULL;
		i++;
	}
	convert_flag[0] = (void *)(-1);
	convert_flag['.'] = 
	convert_flag['0'] = 
	convert_flag['1'] = 
	convert_flag['2'] = 
	convert_flag['3'] = 
	convert_flag['4'] = 
	convert_flag['5'] = 
	convert_flag['6'] = 
	convert_flag['7'] = 
	convert_flag['8'] =
	convert_flag['9'] =
	convert_flag['-'] =   
	convert_flag['*'] =  
}
