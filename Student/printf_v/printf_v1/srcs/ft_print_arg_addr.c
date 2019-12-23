/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:50:18 by mravily           #+#    #+#             */
/*   Updated: 2019/12/12 16:54:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_left_addr(t_tool_box *t_box, char *arg)
{
	long long int		len_arg;
	int					i;

	len_arg = ft_strlen(arg);
	//printf("1st_len_arg = %d\n", len_arg);
	if (t_box->pad_zero == TRUE && t_box->pad_space == TRUE && t_box->precision == TRUE)
		ft_padding(t_box, len_arg);
	if (t_box->precision == TRUE && t_box->str_convert == TRUE)
		len_arg = t_box->len_padding;
	if (t_box->pad_space == TRUE && t_box->addr_convert == TRUE)
		ft_padding(t_box, len_arg);
	//printf("2nd_len_arg = %d\n", len_arg);
	i = 0;
	write(1, "0", 1);
	write(1, "x", 1);
	t_box->n_char_display += 2;
	if (t_box->precision == TRUE && t_box->addr_convert == TRUE)
		ft_padding(t_box, len_arg);
	while (i < len_arg)
	{
		write(1, &arg[i], 1);
		t_box->n_char_display++;
		i++;
	}
}

static void		ft_print_right_addr(t_tool_box *t_box, char *arg)
{
	long long int		len_arg;
	int					i;

	len_arg = ft_strlen(arg);
	//printf("len_arg = %d\n", len_arg);
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
	if (t_box->pad_zero == TRUE || t_box->pad_space == TRUE || t_box->pad_dir == RIGHT)
		ft_padding(t_box, len_arg);
}

void		ft_print_arg_addr(t_tool_box *t_box, char *arg)
{
	//TEST6
	if (t_box->pad_dir == LEFT)
		ft_print_left_addr(t_box, arg);
	else if (t_box->pad_dir == RIGHT)
		ft_print_right_addr(t_box, arg);
}
