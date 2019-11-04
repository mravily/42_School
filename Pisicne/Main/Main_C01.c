/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_C01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:39:26 by mravily           #+#    #+#             */
/*   Updated: 2019/09/28 20:39:26 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ****************************** */
/*      ex07 ft_rev_int_tab       */
/* ****************************** */

#include <stdio.h>
int        main(void)
{
    int tab[] = {1,2,3,4,5,6};

    ft_rev_int_tab(tab, 6);

	/*  A placer sous la boucle while dans la fonction
	
	i = 0;
	while (i < size)
		printf("%d", tab[i++]);

	*/
}

/* ****************************** */
/*      ex08 ft_sort_int_tab      */
/* ****************************** */

#include <stdio.h>
int        main(void)
{
    int tab[] = {7,2,8,3,9,1};

    ft_sort_int_tab(tab, 6);

    /*  A placer sous la boucle while dans la fonction
    
    i = 0;
    while (i < size)
        printf("%d", tab[i++]);
    */
}