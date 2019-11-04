/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:29:11 by mravily            #+#    #+#             */
/*   Updated: 2019/10/11 22:49:11 by mravily           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int fact;

	if (nb >= 1)
		fact = (nb * ft_recursive_factorial(nb - 1));
	else 
		return (1);
	return (fact);
}

