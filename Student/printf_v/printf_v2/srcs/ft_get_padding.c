/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:07:40 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 14:40:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_get_padding(t_tool_box *t_box, const char *format, int *i)
{
	int		nbr;

	printf("str = %s\n", format + *i);
	nbr = ft_atoi_index(format + *i);
	printf("nbr = %d\n", nbr);
	if (t_box->f_precis == FALSE)
		t_box->len_pad = nbr;
	else if (t_box->f_precis == TRUE)
		t_box->len_precis = nbr;
}
