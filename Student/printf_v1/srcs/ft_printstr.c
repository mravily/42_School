/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 01:00:19 by mravily           #+#    #+#             */
/*   Updated: 2019/12/12 16:55:12 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_printstr(char *str, t_tool_box *t_box)
{
	char	*ret;

	if (!str)
		return (ret = "(null)");
	if (*str == '\0')
	{
		t_box->empty_str = TRUE;
		return (str);
	}
	else
		return (str);
}
