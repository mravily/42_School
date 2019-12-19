/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_deci.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:42:31 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/03 17:11:14 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_unsigned_deci(unsigned int nbr)
{
	char					*base;
	size_t					base_len;
	size_t					nbr_len;
	char					*result;

	base = "0123456789";
	base_len = ft_strlen(base);
	nbr_len = ft_nbrlen(nbr, base_len);
	result = ft_strnew(nbr_len);
	result[nbr_len] = '\0';
	nbr_len--;
	while (nbr >= base_len)
	{
		result[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
		nbr_len--;
	}
	result[nbr_len] = base[nbr % base_len];
	return (result);
}
