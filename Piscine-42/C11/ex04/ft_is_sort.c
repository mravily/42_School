/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:05:39 by mravily           #+#    #+#             */
/*   Updated: 2019/09/19 14:25:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < length - 1)
	{
		k = (*f)(tab[i], tab[i + 1]);
		if (k < 0)
			k = -1;
		else if (k > 0)
			k = 1;
		if (k != 0 && j != 0 && j != k)
			return (0);
		j = k;
		i++;
	}
	return (1);
}
