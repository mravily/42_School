/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 01:00:19 by mravily           #+#    #+#             */
/*   Updated: 2019/12/16 16:43:45 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_printstr(char *str, t_tool_box *t_box)
{
	char	*ret;

	if (!str)
	{
		if (!(ret = (char *)malloc(sizeof(char) * 6 + 1)))
			return (NULL);
		ret = "(null)";
		ret[6] = '\0';
		return (ret);
	}
	if (!(ret = (char *)malloc(sizeof(char) * 6 + 1)))
		return (NULL);

	if (*str == '\0')
	{
		t_box->empty_str = TRUE;
		return (ret = str);
	}
	else
		return (ret = str);
}
