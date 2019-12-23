/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:02:44 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 13:24:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_right(t_tool_box *t_box, char *arg,
long long int len_arg)
{
	int				i;

	//PRINTPOS;
	//PRINT_PAD;
	i = 0;
	if ((t_box->len_pad > 0 && t_box->f_zero == FALSE &&
		(t_box->f_precis == FALSE || t_box->len_precis <= 0)) ||
		(t_box->len_pad > 0 && t_box->f_zero == TRUE && t_box->f_precis == TRUE && t_box->len_precis == 0))
	{
		ft_padding_right(t_box, arg);
	}
	else if (t_box->f_precis == TRUE && t_box->len_precis > 0)
	{
		ft_print_precise(t_box, arg, i, len_arg);
	}
	else if (t_box->f_zero == TRUE && (t_box->f_precis == FALSE || t_box->len_precis < 0))
		ft_padding_zero(t_box, arg, &i);
	if (t_box->f_precis == FALSE || t_box->len_precis <= 0)
	{
		while (i < len_arg)
		{
			write(1, &arg[i], 1);
			t_box->printed_char++;
			i++;
		}
	}
}

static void		ft_print_left(t_tool_box *t_box, char *arg,
long long int len_arg)
{
	int					i;

	//PRINTPOS;
	//printf("arg = %s\n", arg);
	i = 0;
	if (t_box->f_precis == FALSE || t_box->len_precis <= 0)
	{
		while (i < len_arg)
		{
			write(1, &arg[i], 1);
			t_box->printed_char++;
			i++;
		}
	}
	
	if (t_box->f_precis == TRUE && t_box->len_precis > 0)
	{
		//PRINTPOS;
		ft_print_precise(t_box, arg, i, len_arg);
	}
	else
	{
		//PRINTPOS;
		ft_padding_left(t_box, i, len_arg);
	}
}

void		ft_print_arg(t_tool_box *t_box, char *arg)
{
	long int	len_arg;

	len_arg = (arg[0] == '\x00' && t_box->c_char == TRUE) ? 1 : ft_strlen(arg);
	//printf("pad_dir = %d\n", t_box->pad_dir);
	if (t_box->pad_dir == RIGHT)
	{
		ft_print_right(t_box, arg, len_arg);
	}
	else if (t_box->pad_dir == LEFT)
	{	//PRINTPOS;
		ft_print_left(t_box, arg, len_arg);
	}
	ft_reset_flags(t_box);
	free(arg);
}
