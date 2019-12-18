/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:12:21 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 14:27:59 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_left(t_tool_box *t_box, char *arg, long long int len_arg)
{
	int		i;

	i = 0;
	if (t_box->len_pad > 0 && t_box->f_zero == FALSE
		&& (t_box->f_precis == FALSE || t_box->len_precis < 0))
		ft_padding_left(t_box, arg);
	if (t_box->f_precis == TRUE && t_box->len_precis >= 0)
		ft_padding_precise(t_box, arg, i, len_arg);
	if (t_box->f_precis == FALSE || t_box->len_precis < 0)
	{
		while (i < len_arg)
		{
			write(1, &arg[i], 1);
			t_box->cmpt_char++;
			i++;
		}
	}
}

static void		ft_print_right(t_tool_box *t_box, char *arg, long long int len_arg)
{
	int		i;

	i = 0;
	if (t_box->f_precis == FALSE)
	{
		while (i < len_arg)
		{
			write(1, &arg[i], 1);
			t_box->cmpt_char++;
			i++;
		}
	}
	if (t_box->f_precis == TRUE && t_box->f_precis > 0)
		ft_print_precise(t_box, arg, i, len_arg);
	else
		ft_print_left_padding(t_box, i, len_arg);
}

void			ft_print_arg_str(t_tool_box *t_box, char *arg)
{
	long long int	len_arg;

	len_arg = (arg[0] == '\x00' && t_box->c_char == TRUE) ? 1 : ft_strlen(arg);
	if (t_box->pad_dir == LEFT)
	{
		ft_print_left(t_box, arg, len_arg);
	}
	else if (t_box->pad_dir == RIGHT)
	{
		ft_print_right(t_box, arg, len_arg);
	}
	ft_reset_flags(t_box);
	free(arg);
}
