/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:27:24 by rsoto-in          #+#    #+#             */
/*   Updated: 2019/09/08 18:18:09 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char ***ft_malloc(char ***table, int side, int size);

void ft_print_table(char ***table, int side, int size);

void ft_fill_table(char ***table, int side, int size, char *str);

char	***ft_prepare_table(int side, char *str)
{
	char ***table;

	table = 0;
	table = ft_malloc(table, side, side + 2);
	ft_fill_table(table, side, side + 2, str);
	return (table);
}
