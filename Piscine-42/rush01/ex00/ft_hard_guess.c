/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard_guess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:32:59 by rsoto-in          #+#    #+#             */
/*   Updated: 2019/09/08 22:03:42 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_remove_digits(char ***table, int side, char digit, int position[2]);

int	ft_check_array(char ***table, int side, int *counter);

void ft_check_siblings(char ***table, int side, int *counter);

void	ft_hard_guess(char ***table, int side, int size)
{
	int counter[4];
	int length;

	counter[0] = 0;
	while (counter[0] < size)
	{
		counter[1] = 0;
		while (counter[1] < size)
		{
			counter[2] = 0;
			length = ft_check_array(table, side, counter);
			if (length > 1)
			{
				ft_check_siblings(table, side, counter);
				break;
			}
			counter[1]++;
		}
		counter[0]++;
	}
}

int ft_check_array(char ***table, int side, int *counter)
{
	int i;
	int j;
	int k;
	int size;

	i = counter[0];
	j = counter[1];
	k = 0;
	size = 0;
	while (k < side)
	{
		if (table[i][j][k] != '.')
			size++;
		k++;
	}
	return (size);
}

void ft_check_siblings(char ***table, int side, int *counter)
{
	int k;
	int length;
	int position[2];

	k = counter[2];
	while (k < side)
	{
		position[0] = 1;
		while (position[0] < side - 1)
		{
			length = ft_check_array(table, side, position);
			if (length == 1)
			{
				ft_remove_digits(table, side, table[position[0]][0][0], counter);
			}
			position[0]++;
		}

		position[0] = counter[0];
		while (position[1] < side - 1)
		{
			length = ft_check_array(table, side, position);
			if (length == 1)
			{
				ft_remove_digits(table, side, table[position[0]][0][0], counter);
			}
			position[1]++;
		}
		k++;
	}
}
