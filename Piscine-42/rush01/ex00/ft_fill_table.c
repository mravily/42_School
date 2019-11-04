/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:12:58 by rsoto-in          #+#    #+#             */
/*   Updated: 2019/09/08 21:59:00 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_fill_headers(char ***table, int size, int *counter, char *str);

void ft_fill_body(char ***table, int size, int *counter, char *str);

void ft_fill_content(char ***table, int size, int *counter);

void	ft_fill_table(char ***table, int side, int size, char *str)
{
	int counter[7];

	counter[0] = 0;
	counter[3] = 0;
	counter[4] = (side * 4 * 2) / 2;
	counter[5] = counter[4] + side * 2;
	while (counter[0] < size)
	{
		counter[1] = 0;
		while (counter[1] < size)
		{
			counter[2] = 0;
			counter[6] = 1;
			while (counter[2] < side)
			{
				ft_fill_body(table, size, counter, str);
				counter[2]++;
			}
			counter[1]++;
		}
		counter[0]++;
	}
}

int	ft_fill_headers(char ***table, int size, int *counter, char *str)
{
	int i;
	int j;

	i = counter[0];
	j = counter[1];
	if ((i == 0 && j > 0 && j < size - 1 && counter[2] == 0) ||
		(i == size - 1 && j > 0 && j < size - 1 && counter[2] == 0))
	{
		table[i][j][counter[2]] = str[counter[3]];
		counter[3] += 2;
		return (0);
	}
	else if (j == 0 && i > 0 && i < size - 1 && counter[2] == 0)
	{
		table[i][j][counter[2]] = str[counter[4]];
		counter[4] += 2;
		return (0);
	}
	else if (j == size - 1 && i > 0 && i < size - 1 && counter[2] == 0)
	{
		table[i][j][counter[2]] = str[counter[5]];
		counter[5] += 2;
		return (0);
	}
	return (1);
}

void	ft_fill_content(char ***table, int size, int *counter)
{
	int i;
	int j;
	int k;

	i = counter[0];
	j = counter[1];
	k = counter[2];
	if (i > 0 && i < size - 1 && j > 0 && j < size - 1)
	{
		table[i][j][k] = '0' + counter[6];
		counter[6]++;
	}
	else
	{
		table[i][j][k] = '.';
	}
}

void	ft_fill_body(char ***table, int size, int *counter, char *str)
{
	int i;
	int j;
	int isheader;

	i = counter[0];
	j = counter[1];
	isheader = ft_fill_headers(table, size, counter, str);
	if (isheader != 0)
	{
		ft_fill_content(table, size, counter);
	}
}
