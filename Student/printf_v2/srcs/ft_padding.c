/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 00:50:59 by mravily           #+#    #+#             */
/*   Updated: 2019/12/16 16:49:29 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_padding_zero(t_tool_box *t_box, int len_arg)
{
	int		len_to_print;
	int		len_padding;
	int		len_precis;
	int		len_asterix;

	//PRINTPOS;
	len_asterix = t_box->len_asterix;
	len_precis = t_box->len_precis;
	len_padding = t_box->len_zero;
	if (len_asterix < 0)
		len_asterix *= (-1);
	if (len_padding == 0 && len_asterix == 0 && len_precis == 0)
		len_to_print = 0;
	else
		len_to_print = (len_arg - len_padding - len_precis - len_asterix);
	if (len_to_print < 0)
		len_to_print *= (-1);
	//LEN_ARG;
	//LEN_PAD;
	//LEN_PREC;
	//LEN_ATX;
	//LEN_PRINT;
	while (len_to_print > 0)
	{
		write(1, "0", 1);
		len_to_print--;
		t_box->cmpt_char++;
	}
}
static void		ft_padding_space(t_tool_box *t_box, int len_arg)
{
	int		len_to_print;
	int		len_padding;
	int		len_precis;
	int		len_asterix;

	//PRINTPOS;
	len_precis = t_box->len_precis;
	len_padding = t_box->len_space;
	len_asterix = t_box->len_asterix;
	if (len_asterix < 0)
		len_asterix *= (-1); 
	if ((len_padding == 0 && len_asterix == 0 && len_precis == 0 )|| (len_arg > len_asterix && len_precis == 0 && len_padding == 0))
		len_to_print = 0;
	else
		len_to_print = (len_arg - len_padding - len_precis - len_asterix);
	if (len_to_print < 0)
		len_to_print *= (-1);
	//LEN_ARG;
	//LEN_PAD;
	//LEN_PREC;
	//LEN_ATX;
	//LEN_PRINT;
	while (len_to_print > 0)
	{
		write(1, " ", 1);
		len_to_print--;
		t_box->cmpt_char++;
	}
}

static void		ft_padding_field_width(t_tool_box *t_box, int len_arg)
{
	int		len_to_print;
	int		len_padding;
	int		len_precis;
	int		len_asterix;

	//PRINTPOS;
	len_precis = t_box->len_precis;
	len_padding = t_box->len_field_width;
	len_asterix = t_box->len_asterix;
	if (len_asterix < 0)
		len_asterix *= (-1);
	if ((len_padding == 0 && len_asterix == 0) || (len_arg > (len_padding - len_precis)))
	{
		//PRINTPOS;
		len_to_print = 0;
	}
	else
		len_to_print = (len_arg - len_padding);
	if (len_to_print < 0)
		len_to_print *= (-1);
	//LEN_PREC;
	//LEN_ARG;
	//LEN_PAD;
	//LEN_ATX;
	//LEN_PRINT;
	while (len_to_print > 0)
	{
		write(1, " ", 1);
		len_to_print--;
		t_box->cmpt_char++;
	}
}

void			ft_padding(t_tool_box *t_box, int len_arg)
{
	//printf("pad_dir = %d\n", t_box->pad_dir);
	//printf("f_precis = %d\n", t_box->f_precis);
	//printf("len_precis = %d\n", t_box->len_precis);
	//PRINTPOS;
	if (t_box->f_zero == TRUE || (t_box->f_zero == TRUE && t_box->f_precis == TRUE) || (t_box->f_zero == TRUE && t_box->f_asterix == TRUE))
	{
		//PRINTPOS;
		ft_padding_zero(t_box, len_arg);
	}
	else if (t_box->f_field_width == TRUE && (t_box->f_precis == TRUE || t_box->f_asterix == TRUE))
	{	
		//PRINTPOS;
		ft_padding_field_width(t_box, len_arg);
	}
	else if (t_box->pad_dir == RIGHT && t_box->f_precis == TRUE && t_box->len_precis != 0)
	{
		//PRINTPOS;
		ft_padding_zero(t_box, len_arg);
	}
	else if (t_box->f_space == TRUE || (t_box->f_space == TRUE && t_box->f_precis == TRUE) || (t_box->f_space == TRUE && t_box->f_asterix == TRUE))
	{
		//PRINTPOS;
		ft_padding_space(t_box, len_arg);
	}
}