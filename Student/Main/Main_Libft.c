/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_Libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:38:46 by mravily           #+#    #+#             */
/*   Updated: 2019/11/05 12:34:56 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************* */
/*               ft_memset               */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	char str[] = {"C'est une fonction de la librairie string.h"};
	puts(str);
	ft_memset(str, '*', 5);
	puts(str);
}

/* ************************************* */
/*               ft_memcpy               */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	char dest[] = {"a l'envers a l'envers"};
	char src[] = {"a l'endroit a l'envers"};

	puts(dest);
	ft_memcpy(dest, src, 11);
	puts(dest);
}

/* ************************************* */
/*               ft_memccpy              */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	char dest[] = {"Petit test a la con histoire de"};
	char src [] = {"Gros test a la con encore"};

	puts(ft_memccpy(dest, src, 'a', 16));
}

/* ************************************* */
/*               ft_memchr               */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	char s[] = {"J'aimerai bien travailler dans un Zoo"};

	puts(ft_memchr(s,'Z',38));
}

/* ************************************* */
/*               ft_memcmp               */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	char s1[] = {"Petit test a la con histoire de"};
	char s2[] = {"Petit test a la con encore"};

	printf("%d",ft_memcmp(s1, s2, 16));
}

/* ************************************* */
/*               ft_strdup               */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	char s[] = {"a string duplaction it's easy, don't be afraid"};

	puts(ft_strdup(s));
}

/* ************************************* */
/*               ft_strstr               */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	char baystack[] = {"sodom et ghomor sont des sodomites, et bien d'autres choses"};
	char needle [] = {"fourtou"};

	puts(ft_strstr(baystack, needle));
}

/* ************************************* */
/*               ft_strjoin              */
/* ************************************* */

#include <stdio.h>
int		main(void)
{
	const char	s1[] = {"1st part of string "};
	const char	s2[] = {"2nd part of string"};

	puts(ft_strjoin(s1, s2));
}
