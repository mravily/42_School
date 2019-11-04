/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_C02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:54:40 by mravily           #+#    #+#             */
/*   Updated: 2019/09/29 15:54:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ****************************** */
/*          ex00 ft_strcpy        */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char dest[] = {"La programation c'est cool"};
	char src[] = {"Plutot sympa"};

	printf("%s", ft_strcpy(dest, src));
}

/* ****************************** */
/*         ex01 ft_strncpy        */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char dest[] = {"La programation c'est cool"};
	char src[] = {"Plutot sympa"};

	printf("%s", ft_strncpy(dest, src, 6));
}

/* ****************************** */
/*      ex02 ft_str_is_alpha      */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str_alpha[] = {"aBcDeF"};
	char str_other[] = {"aBc*e5"};

	printf("return = %d", ft_str_is_alpha(str_other));
} 

/* ****************************** */
/*     ex03 ft_str_is_numeric     */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str_num[] = {"498156"};
	char str_other[] = {"aBc*e5"};

	printf("return = %d", ft_str_is_numeric(str_other));
}

/* ****************************** */
/*    ex04 ft_str_is_lowercase    */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str_lower[] = {"amateratsu"};
	char str_other[] = {"WeLL DONe"};

	printf("return = %d", ft_str_is_lowercase(str_other));
}

/* ****************************** */
/*    ex05 ft_str_is_uppercase    */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str_upper[] = {"NANIII"};
	char str_other[] = {"KsoOoOo Dane"};

	printf("return = %d", ft_str_is_uppercase(str_other));
}

/* ****************************** */
/*    ex06 ft_str_is_printable    */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str[] = {"Oma ewa mo shiinderu !!"};

	printf("%s", ft_str_is_printable(str));
}

/* ****************************** */
/*        ex07 ft_strupcase       */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str[] = {"Oma ewa mo shiinderu !!"};

	printf("%s", ft_strupcase(str));
}

/* ****************************** */
/*       ex08 ft_strlowcase       */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str[] = {"oMA eWA mO sHIIDERU !!"};

	printf("%s", ft_strlowcase(str));
}

/* ****************************** */
/*     ex09 ft_strcapitalize      */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char str[] = {" Yoooo, cEcI eST uN peTit tEst a la coN.. 42mots quarante-deux; cinquante+et+un"};

	printf("%s", ft_strcapitalize(str));
}

/* ****************************** */
/*         ex09 ft_strlcpy        */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char dest[] = {"La programation c'est cool"};
	char src[] = {"Plutot sympa"};

	printf("Taille de la chaine copier = %d", ft_strlcpy(dest, src, 13));
}
