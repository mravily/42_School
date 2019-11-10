/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:26:49 by marvin            #+#    #+#             */
/*   Updated: 2019/11/08 13:26:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int i;
	int res;
	int cmpt_neg;
	int cmpt_pos;

	i = 0;
	res = 0;
	cmpt_neg = 0;
	cmpt_pos = 0;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			cmpt_neg++;
		else
			cmpt_pos++;
		i++;
	}
	printf("2nd i = %d\n", i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	printf("cmpt_neg = %d\n", cmpt_neg);
	printf("cmpt_pos = %d\n", cmpt_pos);
	
	if (cmpt_neg == 1)
		return (-res);
	if (cmpt_pos == 1 || cmpt_pos == 0)
		return (res);
	else if (cmpt_neg == 1 && cmpt_pos == 1)
		return (0);
	else 
		return (0);
}

#include <stdio.h>
int		main(void)
{
	const char nptr[]= {"+-53486"};
	int i1 = atoi(nptr);
	int i2 = ft_atoi(nptr);
	printf("\n");
	if (i1 == i2)
		printf("TEST_SUCCESS\n");
	else
		printf("TEST_FAILED\n");
	printf("\n");
	printf("Diff :\n");
	printf("atoi = %d\n", i1);
	printf("ft_atoi = %d\n", i2);

}