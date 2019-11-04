/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_C04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:39:03 by mravily           #+#    #+#             */
/*   Updated: 2019/10/09 22:39:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ****************************** */
/*          ex00 ft_strlen        */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str[] = {"chaine de caractaire a la con"};

	printf("Taille de la chaine = %d", ft_strlen(str));
}

/* ****************************** */
/*          ex01 ft_putstr        */
/* ****************************** */

int		main(void)
{
	char str[] = {"encore une str pour tester"};

	ft_putstr(str);
}

/* ****************************** */
/*          ex02 ft_putnbr        */
/* ****************************** */

int		main(void)
{
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-150);
	ft_putchar('\n');
	ft_putnbr(42);
}