/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largest_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:34:01 by rsoto-in          #+#    #+#             */
/*   Updated: 2019/09/08 20:41:20 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_remove_digits(char ***table, int side, char digit, int position[2]);

void ft_check_cols_a(char ***table, int side, int size, int *counter);

void ft_check_cols_b(char ***table, int side, int size, int *counter);

void ft_check_rows_a(char ***table, int side, int size, int *counter);

void ft_check_rows_b(char ***table, int side, int size, int *counter);

void	ft_largest_num(char ***table, int side, int size, int *counter)
{
	if (table[counter[0]][counter[1]][0] == ('0' + side))
	{
		ft_check_cols_a(table, side, size, counter);
		ft_check_cols_b(table, side, size, counter);
		ft_check_rows_a(table, side, size, counter);
		ft_check_rows_b(table, side, size, counter);
	}
}

void	ft_check_cols_a(char ***table, int side, int size, int *counter)
{
	char startnum;
	int	position[2];

	startnum = '1';
	if (counter[0] == 0 && counter[1] > 0 && counter[1] < size - 1)
	{
		position[0] = counter[0] + 1;
		position[1] = counter[1];
		while (position[0] < size - 1)
		{
			ft_remove_digits(table, side, startnum, position);
			startnum++;
			position[0]++;
		}
	}
}

void	ft_check_cols_b(char ***table, int side, int size, int *counter)
{
	char startnum;
	int	position[2];

	startnum = '1';
	if (counter[0] == size - 1 && counter[1] > 0 && counter[1] < size - 1)
	{
		position[0] = counter[0] - 1;
		position[1] = counter[1];
		while (position[0] > 0)
		{
			ft_remove_digits(table, side, startnum, position);
			startnum++;
			position[0]--;
		}
	}
}

void	ft_check_rows_a(char ***table, int side, int size, int *counter)
{
	char startnum;
	int	position[2];

	startnum = '1';
	if (counter[1] == 0 && counter[0] > 0 && counter[0] < size - 1)
	{
		position[0] = counter[0];
		position[1] = counter[1] + 1;
		while (position[1] < size - 1)
		{
			ft_remove_digits(table, side, startnum, position);
			startnum++;
			position[1]++;
		}
	}
}

void	ft_check_rows_b(char ***table, int side, int size, int *counter)
{
	char startnum;
	int	position[2];

	startnum = '1';
	if (counter[1] == size - 1 && counter[0] > 0 && counter[0] < size - 1)
	{
		position[0] = counter[0];
		position[1] = counter[1] - 1;
		while (position[1] > 0)
		{
			ft_remove_digits(table, side, startnum, position);
			startnum++;
			position[1]--;
		}
	}
}
