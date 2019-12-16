/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:29:02 by mravily           #+#    #+#             */
/*   Updated: 2019/11/21 09:44:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nb_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	if (n < 0)
		nbr = (unsigned int)(n * (-1));
	else
		nbr = (unsigned int)n;
	size = (unsigned int)get_nb_size(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + ((n < 0 ? 1 : 0))))))
		return (NULL);
	if (n < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (nbr >= 10)
	{
		str[i--] = (char)(nbr % 10 + '0');
		nbr /= 10;
	}
	str[i] = (char)(nbr + '0');
	str[size] = '\0';
	return (str);
}
