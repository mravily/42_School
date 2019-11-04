/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_C05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:44:53 by mravily           #+#    #+#             */
/*   Updated: 2019/10/11 21:44:53 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* *************************************** */
/*        ex00 ft_iterative_factorial      */
/* *************************************** */

#include <stdio.h>
int		main(void)
{
	int nb;

	nb = 5;	
	printf("%d! = %d", nb, ft_iterative_factorial(nb));
}

/* *************************************** */
/*        ex01 ft_recursive_factorial      */
/* *************************************** */

#include <stdio.h>
int		main(void)
{
	int nb;

	nb = 5;	
	printf("%d! = %d", nb, ft_recursive_factorial(nb));
}

/* *************************************** */
/*         ex02 ft_iterative_power         */
/* *************************************** */

#include <stdio.h>
int		main(void)
{
	int nb;
	int power;

	nb = 5;
	power = 0;
	printf("%d Puissance %d = %d", nb, power, ft_iterative_power(nb, power));
}

/* *************************************** */
/*         ex03 ft_recursive_power         */
/* *************************************** */

#include <stdio.h>
int		main(void)
{
	int nb;
	int power;

	nb = 5;
	power = 5;
	printf("%d Puissance %d = %d", nb, power, ft_recursive_power(nb , power));
}

/* *************************************** */
/*             ex04 ft_fibonacci           */
/* *************************************** */

#include <stdio.h>
int		main(void)
{
	int index;

	index = 8;
	printf("La nombre de Fibonnaci de %d = %d", index, ft_fibonacci(index));
}