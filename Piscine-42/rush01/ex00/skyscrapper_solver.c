/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapper_solver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoto-in <rsoto-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:17:02 by richard           #+#    #+#             */
/*   Updated: 2019/09/08 21:59:52 by rsoto-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_solve_puzzle(char *str);

int	main(int args, char **argv)
{
	if (args == 2)
	{
		ft_solve_puzzle(argv[1]);
	}
	else
	{
		// Print "Error"
	}
	return (0);
}
