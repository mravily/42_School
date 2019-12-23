/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:32:45 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 12:20:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_padding_right(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	j;
	int			len_pad;

	//PRINTPOS;
	//PRINT_PAD;
	//printf("arg = %s\n", arg);
	len_pad = t_box->len_pad;
	i = 0;
	j = (arg[0] == '\x00' && t_box->c_char == 1) ? 1 : ft_strlen(arg);
	//printf("j = %ld\n", j);
	while (i < (len_pad - j))
	{
		write(1, " ", 1);
		t_box->printed_char++;
		i++;
	}
}
