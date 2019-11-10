/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 05:41:49 by marvin            #+#    #+#             */
/*   Updated: 2019/11/08 05:41:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

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

char	*ft_itoa(int n)
{
	char 			*str;
	unsigned int	nbr;
	unsigned int	size;
	unsigned int 	i;
	printf("n = %d\n", n);
	i = 0;
	if (n < 0)
		nbr = (unsigned int)(n * -1);
	else
		nbr = (unsigned int)n;
	printf("nbr = %d\n", nbr);
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
	str[i] = (char)(nbr % 10 + '0');
	str[size] = '\0';
	return (str);
}

int		main(void)
{
	unsigned int n = {-6518};
	printf("return = %s",ft_itoa(n));
}