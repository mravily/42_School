/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:30:36 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 13:48:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_get_padding(t_tool_box *t_box, const char *format, size_t *i)
{
	int		nbr;

	//printf("1st_str = %s\n", format + *i);
	nbr = ft_atoi_index(format + *i);
	while (ft_isdigit(format[*i]) == 1)
		(*i)++;
	//printf("2nd_str = %s\n", format + *i);
	//printf("nbr = %d\n", nbr);
	if (t_box->f_precis == FALSE)
	{
		//PRINTPOS;
		t_box->len_pad = nbr;
		//PRINT_PAD;
	}
	else if (t_box->f_precis == TRUE)
	{
		t_box->len_precis = nbr;
	}
}
