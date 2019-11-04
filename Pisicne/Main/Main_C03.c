/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_C03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:34:25 by mravily           #+#    #+#             */
/*   Updated: 2019/10/08 19:34:25 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ****************************** */
/*          ex00 ft_strcmp        */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char s1[] = {"abcde"};
	char s2[] = {"abcda"};  

	printf("Diff = %d", ft_strcmp(s1, s2));

	// Diff = 4; car a + 4 = e dans la table ASCII
}

/* ****************************** */
/*          ex01 ft_strncmp       */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char s1[] = {"sasagero"};
	char s2[] = {"sasagore"};  

	printf("Diff = %d", ft_strncmp(s1, s2, 7));
}

/* ****************************** */
/*          ex02 ft_strcat        */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char dest[24] = {"Oma ewa "};
	char src [] = {"mo Shinderu !!!"};

	printf("%s", ft_strcat(dest, src));
}

/* ****************************** */
/*          ex03 ft_strncat       */
/* ****************************** */

#include <stdio.h>
int		main(void)
{
	char dest[24] = {"Oma ewa "};
	char src [] = {"mo Shinderu !!!"};

	printf("%s", ft_strncat(dest, src, 10));
}

/* ****************************** */
/*          ex04 ft_strstr       */
/* ****************************** */


#include <stdio.h>
int        main(void)
{
    char str[] = {"sodom et gomor sont des sodomites, et bien plus !!!"};
    char to_find[] = {"sodomites"};

    printf("%s", ft_strstr(str, to_find));
}