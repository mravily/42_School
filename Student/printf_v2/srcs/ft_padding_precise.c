/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_precise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:47:33 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 14:54:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_precise_right_pad(t_tool_box *t_box,
													int i, int diff, char *arg)
{
	long int		len_arg;

	len_arg = ft_strlen(arg);
	if (t_box->c_digit == TRUE)
	{
		t_box->len_pad = (arg[0] == '-' && t_box->len_pad >= len_arg) ? t_box->len_pad -= 1 : t_box->len_pad;
		if (t_box->len_precis < len_arg)
			while (i < t_box->len_pad - len_arg)
			{
				write(1, " ", 1);
				t_box->cmpt_char++;
				i++;
			}
		else
			while (i < t_box->len_pad - t_box->len_precis)
			{
				write(1, " ", 1);
				t_box->cmpt_char++;
				i++;
			}
	}
	else
		while (i < t_box->len_pad - t_box->len_precis + diff)
		{
			write(1, " ", 1);
			t_box->cmpt_char++;
			i++;
		}
}

static void		ft_precise_digit(t_tool_box *t_box, char *arg, int i, int nbr_z)
{
	long int len_arg;

	len_arg = ft_strlen(arg);
	i = 0;
	if (arg[0] == '-' && nbr_z > 0)
	{
		write(1, "-", 1);
		t_box->cmpt_char++;
		t_box->len_pad -= 1;
	}
	while (i < nbr_z)
	{
		write(1, "0", 1);
		t_box->cmpt_char++;
		i++;
	}
	i = (arg[0] == '-' && nbr_z > 0) ? 1 : 0;
	while (i < len_arg)
	{
		write(1, &arg[i], 1);
		t_box->cmpt_char++;
		i++;
	}
}

void			ft_precise_precise(t_tool_box *t_box,
												char *arg, int i, long int len)
{
	int			nb_zero;
	int			sign_neg;

	sign_neg = (arg[0] == '-') ? 1 : 0;
	nb_zero = ((t_box->len_precis - len + sign_neg) < 0) ? 0 : (t_box->len_precis - len + sign_neg);
	if (t_box->len_pad > 0 && t_box->pad_dir == RIGHT && arg[0] != '%')
		ft_precise_right_pad(t_box, i, nb_zero, arg);
	if (t_box->len_pad > 0 && t_box->pad_dir == RIGHT && arg[0] == '%' && t_box->f_zero == FALSE)
		ft_precise_right_pad(t_box, i, nb_zero, arg);
	if (arg[0] == '%' && t_box->f_zero == TRUE)
		ft_print_zero(t_box, arg, &i);
	if (t_box->c_digit == FALSE)
		while (i < len && i < t_box->len_precis)
		{
			write(1, &arg[i], 1);
			t_box->cmpt_char++;
			i++;
		}
	else if (t_box->c_digit == TRUE)
		ft_precise_digit(t_box, arg, i, nb_zero);
	if (t_box->len_pad > 0 && t_box->pad_dir == LEFT)
		ft_padding_left(t_box, len);
}
