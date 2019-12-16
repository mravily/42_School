/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_value_to_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:45:50 by mravily           #+#    #+#             */
/*   Updated: 2019/12/13 23:47:22 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_nb_unsigned_size(unsigned long long int nb,
unsigned int len_base)
{
	unsigned int		size;

	size = 0;
	while (nb >= len_base)
	{
		nb = nb / len_base;
		size++;
	}
	return (size + 1);
}

static int	get_nb_signed_size(long long int nb, unsigned int len_base)
{
	unsigned int		size;

	size = 0;
	while (nb >= len_base)
	{
		nb = nb / len_base;
		size++;
	}
	return (size + 1);
}

static char	*ft_convert_unsigned_to_base(t_data *data, char *base,
t_tool_box *t_box)
{
	char						*str;
	unsigned long long int		nbr;
	unsigned long long int		size;
	unsigned long long int		i;
	unsigned long long int		len_base;

	len_base = ft_strlen(base);
	nbr = data->u_ll_int;
	//printf("data.u_ll_int = %lld\n", data.u_ll_int);
	//printf("nbr = %lld\n", nbr);
	size = get_nb_unsigned_size(nbr, len_base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if ((t_box->lenght_modif == HH && nbr < 0) || (t_box->lenght_modif == HH && nbr < 0))
		size -= (t_box->lenght_modif == H) ? 4 : 6;
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

static char	*ft_convert_signed_to_base(t_data *data, char *base,
t_tool_box *t_box)
{
	char			*str;
	long long int	nbr;
	long long int	size;
	long long int	i;
	long long int	len_base;

	len_base = ft_strlen(base);

	nbr = data->ll_int;
	size = get_nb_signed_size(nbr, len_base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if ((t_box->lenght_modif == HH && nbr < 0) || (t_box->lenght_modif == HH && nbr < 0))
		size -= (t_box->lenght_modif == H) ? 4 : 6;
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

char		*ft_convert_value_to_base(t_data *data, char *base, t_tool_box *t_box)
{
	if (t_box->c_digit == TRUE)
	{
		//PRINTPOS;
		return (ft_convert_signed_to_base(data, base, t_box));
	}
	else
	{
		//PRINTPOS;
		return (ft_convert_unsigned_to_base(data, base, t_box));
	}
}
