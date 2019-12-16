/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:15:15 by mravily           #+#    #+#             */
/*   Updated: 2019/12/14 00:30:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_left(t_tool_box *t_box, char *arg)
{
	long long int		len_arg;
	int					i;

	len_arg = ft_strlen(arg);

	if (t_box->pad_zero == TRUE || (t_box->pad_space == TRUE && t_box->precision == FALSE))
	{
		//PRINTPOS;
		ft_padding(t_box, len_arg);
	}
	if (t_box->precision == TRUE && t_box->char_convert == FALSE
	&& t_box->empty_str == FALSE && t_box->pad_zero == FALSE)
	{
		//PRINTPOS;
		ft_padding(t_box, len_arg);
	}
	if (t_box->precision == TRUE && t_box->str_convert == TRUE)
	{
		//PRINTPOS;
		len_arg = t_box->len_padding;
	}
	i = 0;
	if (t_box->arg_neg == TRUE && t_box->digit == FALSE && t_box->pad_zero == FALSE)
		t_box->n_char_display++;
	if (t_box->empty_str == FALSE)
	{
		while (i < len_arg)
		{
			write(1, &arg[i], 1);
			t_box->n_char_display++;
			i++;
		}
	}
}

static void		ft_print_right(t_tool_box *t_box, char *arg)
{
	long long int		len_arg;
	int					i;

	len_arg = ft_strlen(arg);
	if (t_box->arg_neg == TRUE && t_box->pad_dir == RIGHT)
	{
		write(1, "-", 1);
		t_box->n_char_display++;
	}
	i = 0;
	while (i < len_arg)
	{
		write(1, &arg[i], 1);
		t_box->n_char_display++;
		i++;
	}
	if (t_box->pad_zero == TRUE || t_box->pad_space == TRUE)
	{
		PRINTPOS;
		ft_padding(t_box, len_arg);
	}
}

void		ft_print_arg(t_tool_box *t_box, char *arg)
{
	if (t_box->pad_dir == LEFT)
	{
		//PRINTPOS;
		ft_print_left(t_box, arg);
	}
	else if (t_box->pad_dir == RIGHT)
	{
		//PRINTPOS;
		ft_print_right(t_box, arg);
	}
	ft_reset_flag(t_box);
}
