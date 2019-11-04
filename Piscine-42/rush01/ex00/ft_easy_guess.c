/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easy_guess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:13:19 by rsoto-in          #+#    #+#             */
/*   Updated: 2019/09/08 20:52:31 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_largest_num(char ***table, int side, int size, int *counter);

void ft_largest_num(char ***table, int side, int size, int *counter);

void ft_less_largest_num(char ***table, int side, int size, int *counter);

void	ft_easy_guess(char ***table, int side, int size)
{
	int counter[4];

	counter[0] = 0;
	while (counter[0] < size)
	{
		counter[1] = 0;
		while (counter[1] < size)
		{
			counter[2] = 0;
			while (counter[2] < side)
			{
				ft_largest_num(table, side, size, counter);
				ft_less_largest_num(table, side, size, counter);
				counter[2]++;
			}
			counter[1]++;
		}
		counter[0]++;
	}
}
