/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_octa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:36:45 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 15:54:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_octa(long long int nbr)
{
	char	*base;
	char	*result;

	base = "01234567";
	result = ft_itoa_base(nbr, base);
	return (result);
}
