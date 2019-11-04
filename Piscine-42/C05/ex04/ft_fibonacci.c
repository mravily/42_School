/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:05:01 by mravily           #+#    #+#             */
/*   Updated: 2019/09/09 16:19:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int result;

	if (index < 0)
		return (-1);
	if (index == 1)
		return (index);
	if (index == 0)
		return (0);
	else
		result = (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (result);
}
