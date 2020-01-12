/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:52:38 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 15:53:27 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_i_roof(float p_value)
{
	int			i_value;

	if (p_value == 0)
		return (0);
	i_value = p_value;
	if (p_value < 0)
		return (i_value);
	else
		return (i_value + 1);
}
