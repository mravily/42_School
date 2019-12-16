/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:25:11 by mravily           #+#    #+#             */
/*   Updated: 2019/12/03 22:29:29 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_nb_size(unsigned int nb, unsigned int len_base)
{
	unsigned int	size;

	size = 0;
	while (nb >= len_base)
	{
		nb = nb / len_base;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa_base(int n, char *base)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	size;
	unsigned int	i;
	unsigned int	len_base;

	i = 0;
	len_base = ft_strlen(base);
	nbr = (n < 0 ? n * (-1) : n);
	size = get_nb_size(nbr, len_base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + ((n < 0 ? 1 : 0))))))
		return (NULL);
	if (n < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (nbr >= len_base)
	{
		str[i--] = base[nbr % len_base];
		nbr /= len_base;
	}
	str[i] = base[nbr % len_base];
	str[size] = '\0';
	return (str);
}
