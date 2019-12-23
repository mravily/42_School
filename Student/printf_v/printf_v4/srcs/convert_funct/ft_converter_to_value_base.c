/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_to_value_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:45:39 by mravily           #+#    #+#             */
/*   Updated: 2019/12/23 15:05:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	get_nb_unsigned_size(unsigned long long int nbr,
unsigned int len_base)
{
	unsigned int		size;

	if (nbr < 0)
		nbr *= (-1);
	size = 0;
	while (nbr >= len_base)
	{
		nbr /= len_base;
		size++;
	}
	return (size + 1);
}

static int	get_nb_signed_size(long long int nbr, unsigned int len_base)
{
	unsigned int		size;

	size = 0;
	while (nbr >= len_base)
	{
		nbr /= len_base;
		size++;
	}
	return (size + 1);
}

static char	*ft_convert_unsigned_to_base(char *base,
t_flag *flag)
{
	char						*str;
	unsigned long long int		nbr;
	unsigned long long int		size;
	unsigned long long int		i;
	unsigned long long int		len_base;

	len_base = ft_strlen(base);
	nbr = flag->data.u_ll_int;
	//printf("data.u_ll_int = %lld\n", flag->data.u_ll_int);
	//printf("nbr = %lld\n", nbr);
	size = get_nb_unsigned_size(nbr, len_base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if ((flag->lenght_modif == HH && nbr < 0) || (flag->lenght_modif == HH && nbr < 0))
		size -= (flag->lenght_modif == H) ? 4 : 6;
	i = size - 1;
	while (nbr >= len_base)
	{
		str[i--] = base[nbr % len_base];
		nbr /= len_base;
	}
	str[i] = base[nbr % len_base];
	str[size] = '\0';
	//printf("str = %s\n", str);
	return (str);
}

static char	*ft_convert_signed_to_base(char *base,
t_flag *flag)
{
	char			*str;
	long long int	nbr;
	long long int	size;
	long long int	i;
	long long int	len_base;

	len_base = ft_strlen(base);
	nbr = flag->data.ll_int;
	size = get_nb_signed_size(nbr, len_base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if ((flag->lenght_modif == HH && nbr < 0) ||
	(flag->lenght_modif == HH && nbr < 0))
		size -= (flag->lenght_modif == H) ? 4 : 6;
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

char		*ft_convert_value_to_base(char *base, t_flag *flag)
{
	if (flag->converter == 'd')
	{
		//PRINTPOS;
		return (ft_convert_signed_to_base(base, flag));
	}
	else
	{
		//PRINTPOS;
		return (ft_convert_unsigned_to_base(base, flag));
	}
}
