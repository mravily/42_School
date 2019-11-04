/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:45:34 by mravily           #+#    #+#             */
/*   Updated: 2019/10/12 02:35:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int res;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power > 1)
	{
		res = nb * (ft_recursive_power(nb, power - 1));
		return (res);
	}
}
