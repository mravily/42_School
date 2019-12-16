/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:15:15 by mravily           #+#    #+#             */
/*   Updated: 2019/12/14 20:47:38 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_left(t_tool_box *t_box, char *arg)
{
	long long int		len_arg;
	int					i;

	//PRINTPOS;
	len_arg = ft_strlen(arg);
	i = 0;
	if (t_box->flag == TRUE)
		ft_padding(t_box, len_arg);
	while (i < len_arg)
	{
		write(1, &arg[i], 1);
		t_box->cmpt_char++;
		i++;
	}
}

static void		ft_print_right(t_tool_box *t_box, char *arg)
{
	long long int		len_arg;
	int					i;

	//PRINTPOS;
	len_arg = ft_strlen(arg);
	//printf("arg = %s\n", arg);
	i = 0;
	while (i < len_arg)
	{
		write(1, &arg[i], 1);
		t_box->cmpt_char++;
		i++;
	}
	if (t_box->flag == TRUE)
		ft_padding(t_box, len_arg);
}

void		ft_print_arg(t_tool_box *t_box, char *arg)
{
	if (t_box->pad_dir == LEFT)
	{
		ft_print_left(t_box, arg);
	}
	else if (t_box->pad_dir == RIGHT)
	{
		ft_print_right(t_box, arg);
	}
	ft_reset_flags(t_box);
}
