/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:55:54 by mravily           #+#    #+#             */
/*   Updated: 2019/12/17 21:55:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_nb_size(unsigned long long nb, unsigned int len_base)
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

char			*ft_print_addr(void *ptr, char *base)
{
	char				*str;
	unsigned long long	addr;
	unsigned long		size;
	unsigned long		i;
	unsigned long		len_base;

	len_base = ft_strlen(base);
	addr = (unsigned long long)ptr;
	size = get_nb_size(addr, len_base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size - 1;
	while (addr >= len_base)
	{
		str[i--] = base[addr % len_base];
		addr /= len_base;
	}
	str[i] = base[addr % len_base];
	str[size] = '\0';
	return (str);
}
