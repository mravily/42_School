/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:45:40 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 11:46:38 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_padding_left(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	j;

	i = 0;
	j = (arg[0] == '\x00' && t_box->c_char == 1) ? 1 : ft_strlen(arg);
	while (i < t_box->len_pad - j)
	{
		write(1, " ", 1);
		t_box->cmpt_char++;
		i++;
	}
}
