/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:50:18 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 14:50:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_left(t_tool_box *t_box, char *arg, int i, int len)
{
	if (t_box->len_pad > 0 && t_box->f_zero == FALSE)
		ft_padding_left(t_box, arg);
	else if (t_box->f_zero == TRUE)
		ft_padding_zero(t_box, arg, &i);
	write(1, "0x", 2);
	t_box->cmpt_char += 2;
	while (i < len)
	{
		write(1, &arg[i], 1);
		t_box->cmpt_char++;
		i++;
	}
}

static void		ft_print_right(t_tool_box *t_box, char *arg, int i, int len)
{
	write(1, "0x", 2);
	t_box->cmpt_char += 2;
	while (i < len)
	{
		write(1, &arg[i], 1);
		t_box->cmpt_char++;
		i++;
	}
	ft_padding_right(t_box, i, len);
}

void			ft_print_arg_addr(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	len;

	i = 0;
	len = ft_strlen(arg);
	t_box->len_pad -= 2;
	if (t_box->pad_dir == RIGHT)
		ft_printf_right(t_box, arg, i, len);
	else if (t_box->pad_dir == LEFT)
		ft_print_lft(t_box, arg, i, len);
	ft_reset_flags(t_box);
	free(arg);
}
