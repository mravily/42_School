/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:32:29 by mravily           #+#    #+#             */
/*   Updated: 2020/01/03 15:56:50 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_add_suffix(char **p_str, char *p_suffix)
{
	char	*tmp;

	if (p_str == NULL || p_suffix == NULL)
		return ;
	tmp = ft_strdup(*p_str);
	free(*p_str);
	*p_str = ft_strjoin(tmp, p_suffix);
	free(tmp);
}
