/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:52:27 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 15:52:30 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

float		ft_f_roof(float p_value)
{
	float	rounded_value;
	int		i_value;

	if (p_value == 0)
		return (p_value);
	i_value = p_value;
	if (p_value < 0)
	{
		rounded_value = i_value;
		return (rounded_value);
	}
	rounded_value = p_value - i_value;
	if (rounded_value == 0)
	{
		rounded_value = p_value;
		return (rounded_value);
	}
	else
		rounded_value = i_value + 1;
	return (rounded_value);
}
