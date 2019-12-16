/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u_int_to_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:39:57 by mravily           #+#    #+#             */
/*   Updated: 2019/12/11 17:45:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_nb_size(unsigned int nb, unsigned int len_base)
{
	unsigned int 	size;

	size = 0;
	while (nb >= len_base)
	{
		nb = nb / len_base;
		size++;
	}
	return (size + 1);
}

char			*ft_convert_signed_to_base(t_data data, char *base,
t_tool_box *t_box)
{
	char			*str;
	intmax_t		nbr;
	size_t			size;
	size_t			i;
	size_t			len_base;

	len_base = ft_strlen(base);

	nbr = data.intmax_;
	//nbr = check_n(nbr, t_box);
	//printf("nbr_n = %llu\n", nbr);
	size = get_nb_size(nbr, len_base);
	//printf("size = %d\n", size);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if ((t_box->lenght == HH && nbr < 0) || (t_box->lenght == HH && nbr < 0))
	{
		PRINTPOS;
		if (H == TRUE)
		{
			PRINTPOS;
			size -= 4;
		}
		if (HH == TRUE)
		{
			PRINTPOS;	
			size -= 6;
		}
	}
	i = size - 1;
	//printf("nbr = %d\n", nbr);
	while (nbr >= len_base)
	{
		str[i--] = base[nbr % len_base];
		nbr /= len_base;
	}
	str[i] = base[nbr % len_base];
	str[size] = '\0';
	return (str);
}
