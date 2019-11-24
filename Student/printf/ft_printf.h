/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:43:20 by mravily           #+#    #+#             */
/*   Updated: 2019/11/23 13:46:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define LEFT 1
# define RIGHT 0
# define ERROR -1

typedef struct 	s_box
{
		int	n_character_display;
	
}				t_tool_box;

int		ft_printf(const char *format, ...);

#endif
