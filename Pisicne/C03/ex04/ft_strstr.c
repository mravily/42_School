/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:06:44 by mravily           #+#    #+#             */
/*   Updated: 2019/10/09 17:58:44 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] && to_find[j])
    {
        if (str[i] != to_find[j])
            j = 0;
        if (str[i] == to_find[j])
            j++;
        i++;
    }
    return (str + (i - j));
}
