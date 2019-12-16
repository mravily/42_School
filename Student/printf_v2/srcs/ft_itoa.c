/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:54:35 by mravily           #+#    #+#             */
/*   Updated: 2019/12/14 00:47:08 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t		get_nb_size(intmax_t nb)
{
	size_t	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

static long long int				check_n(long long int n, t_tool_box *t_box)
{
	unsigned long long int nbr;

	//printf("nbr_n = %llu\n", n);
	if (n < 0)
	{
		//PRINTPOS;
		nbr = (long long int)(n * (-1));
		t_box->arg_neg = TRUE;
	}
	else
	{
		nbr = (long long int)n;
	}
	return (nbr);
}

char			*ft_itoa(t_data *data, t_tool_box *t_box)
{
	char						*str;
	unsigned long long int		nbr;
	size_t						size;
	size_t						i;

	nbr = data->ll_int;
	//printf("data.ll_int = %lld\n", data.ll_int);
	//printf("nbr = %lld\n", nbr);
	nbr = check_n(nbr, t_box);
	size = get_nb_size(nbr);
	//printf("3nd_nbr = %d\n", nbr);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	//printf("4rd_nbr = %d\n", nbr);
	i = 0;
	if (t_box->arg_neg == TRUE && (str[i] = '-'))
	{
		//PRINTPOS;
		size++;
	}
	i = size - 1;
	//printf("5th_nbr = %d\n", nbr);
	while (nbr >= 10)
	{
		str[i--] = (long long)(nbr % 10 + '0');
		nbr /= 10;
	}
	//printf("6th_nbr = %d\n", nbr);
	str[i] = (char)(nbr + '0');
	//printf("7th_nbr = %s\n", str);
	str[size] = '\0';
	//printf("8th_nbr = %s\n", str);
	return (str);
}
