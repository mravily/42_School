/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:56:40 by rsoto-in          #+#    #+#             */
/*   Updated: 2019/09/08 21:43:12 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_remove_digits(char ***table, int side, char digit, int position[2])
{
	int i;
	int j;
	int k;

	i = position[0];
	j = position[1];
	k = 0;
	while (k < side)
	{
		if (table[i][j][k] != digit)
		{
			table[i][j][k] = '.';
		}
		k++;
	}
}
