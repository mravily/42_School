/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:46:21 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 14:44:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_reset_flags(t_tool_box *t_box)
{
	t_box->pad_dir = LEFT;
	t_box->len_pad = 0;
	t_box->len_precis = 0;
	t_box->f_zero = FALSE;
	t_box->f_space = FALSE;
	t_box->f_precis = FALSE;
	t_box->f_asterisk = FALSE;
	t_box->f_field_width = FALSE;
	t_box->c_char = FALSE;
	t_box->c_digit = FALSE;
	t_box->lenght_modif = 0;

	t_box->sign_convert = FALSE;
}
