/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:13:34 by mravily           #+#    #+#             */
/*   Updated: 2019/12/22 18:57:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BASIC_H
#define FT_PRINTF_BASIC_H

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdarg.h"

enum e_bool
{
	true = 1,
	false = 0
};

# define BOOL enum e_bool

BOOL		ft_strcmp_c(char *p_src, const char p_target);

#endif