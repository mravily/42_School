/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_prefixe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:02:39 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 15:56:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_str_add_prefixe(char *p_prefixe, char **p_str)
{
	char	*tmp;

	if (p_prefixe == NULL || p_str == NULL)
		return ;
	tmp = ft_strdup(*p_str);
	free(*p_str);
	*p_str = ft_strjoin(p_prefixe, tmp);
	free(tmp);
}
