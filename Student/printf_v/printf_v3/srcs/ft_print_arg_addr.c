/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:07:54 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 11:01:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_right(t_tool_box *t_box, char *arg, int i, int len_arg)
{
	if (t_box->len_pad > 0 && t_box->f_zero == FALSE)
	{
		ft_padding_right(t_box, arg);
	}
	else if (t_box->f_zero == TRUE)
		ft_padding_zero(t_box, arg, &i);
	write(1, "0x", 2);
	t_box->printed_char += 2;
	while (i < len_arg)
	{
		write(1, &arg[i], 1);
		t_box->printed_char++;
		i++;
	}
}

static void		ft_print_left(t_tool_box *t_box, char *arg, int i, long int len_arg)
{
	write(1, "0x", 2);
	t_box->printed_char += 2;
	while (i < len_arg)
	{
		write(1, &arg[i], 1);
		t_box->printed_char++;
		i++;
	}
	ft_padding_left(t_box, i, len_arg);
}

void			ft_print_arg_addr(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	len_arg;

	i = 0;
	len_arg = ft_strlen(arg);
	t_box->len_pad -= 2;
	if (t_box->pad_dir == RIGHT)
		ft_print_right(t_box, arg, i, len_arg);
	else if (t_box->pad_dir == LEFT)
		ft_print_left(t_box, arg, i, len_arg);
	ft_reset_flags(t_box);
	free(arg);
}
