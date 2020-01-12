/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:43:33 by mravily           #+#    #+#             */
/*   Updated: 2020/01/04 02:40:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void				add_sign_neg(char **result, t_flag *flag)
{
	ft_str_add_prefixe("-", result);
	flag->arg_neg = false;
}

static void				add_len_padding_2(char **result, t_flag *flag,
int len_arg)
{
	enum e_bool		pad_zero;
	char			*to_add;

	to_add = NULL;
	pad_zero = false;
	if (flag->len_precision < 0 && flag->point == true &&
	flag->padding_direction == right)
	{
		to_add = ft_strnew_c(flag->len_padding - len_arg, '0');
		pad_zero = true;
	}
	else
		to_add = ft_strnew_c(flag->len_padding - len_arg, ' ');
	if (flag->arg_neg == true && (flag->padding_direction == left
	|| pad_zero == false))
		add_sign_neg(result, flag);
	flag->padding_direction == left ?
	ft_str_add_suffix(result, to_add) : ft_str_add_prefixe(to_add, result);
	if (flag->arg_neg == true && flag->padding_direction == right
	&& flag->zero == true)
		add_sign_neg(result, flag);
	free(to_add);
}

static void				add_len_padding(char **result, t_flag *flag,
int len_arg)
{
	char			*to_add;

	to_add = NULL;
	if (flag->arg_neg == true)
		flag->len_padding = flag->len_padding - 1;
	if ((flag->point == false && flag->zero == false) ||
	(flag->point == true && flag->zero == true))
		add_len_padding_2(result, flag, len_arg);
	else
	{
		if (flag->arg_neg == true && (flag->padding_direction == left
		|| flag->zero == false))
			ft_str_add_prefixe("-", result);
		add_padding(result, flag, flag->len_padding - len_arg);
		if (flag->arg_neg == true && flag->padding_direction == right
		&& flag->zero == true)
			ft_str_add_prefixe("-", result);
	}
	free(to_add);
}

static void				add_padd_precs(char **result, t_flag *flag,
int len_arg)
{
	char			*to_add;

	to_add = ft_strnew_c(flag->len_precision - len_arg, '0');
	ft_str_add_prefixe(to_add, result);
	free(to_add);
	to_add = NULL;
	if (flag->arg_neg == true)
	{
		ft_str_add_prefixe("-", result);
		flag->len_padding -= 1;
	}
	if ((len_arg + flag->len_precision) <= flag->len_padding)
	{
		add_padding(result, flag, flag->len_padding -
		(flag->len_precision));
	}
	else if (flag->len_precision < flag->len_padding)
	{
		to_add = ft_strnew_c(flag->len_padding - flag->len_precision, ' ');
		if (flag->padding_direction == left)
			ft_str_add_suffix(result, to_add);
		else
			ft_str_add_prefixe(to_add, result);
	}
	free(to_add);
}

void					add_padding_digit(char **result, t_flag *flag,
int len_arg)
{
	if (len_arg < flag->len_precision)
		add_padd_precs(result, flag, len_arg);
	else if (len_arg < flag->len_padding)
		add_len_padding(result, flag, len_arg);
	else if (flag->arg_neg == true)
		ft_str_add_prefixe("-", result);
}
