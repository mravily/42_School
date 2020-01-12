/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:52:05 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 15:52:09 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

float	ft_f_floor(float p_value)
{
	int		i_value;
	float	result;

	i_value = (int)p_value;
	result = i_value;
	return (result);
}
