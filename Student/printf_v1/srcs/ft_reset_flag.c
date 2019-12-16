/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:24:42 by mravily           #+#    #+#             */
/*   Updated: 2019/12/12 16:47:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_reset_flag(t_tool_box *t_box)
{
	t_box->pad_dir = LEFT;
	t_box->pad_zero = FALSE;
	t_box->len_padding = 0;
	t_box->precision = FALSE;
	t_box->asterix = FALSE;
	t_box->arg_neg = FALSE;
	t_box->str_convert = FALSE;
	t_box->char_convert = FALSE;
	t_box->addr_convert = FALSE;
	t_box->hexa_convert = FALSE;
	t_box->pad_space = FALSE;
	t_box->len_space = 0;
	t_box->digit = FALSE;
	t_box->empty_str = FALSE;
}