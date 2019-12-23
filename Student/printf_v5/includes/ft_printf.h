/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:42:54 by mravily           #+#    #+#             */
/*   Updated: 2019/12/22 18:57:47 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_basic.h"


enum	e_dir
{
	right = 0,
	left = 1
};

# define PAD_DIR enum e_dir
# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)

typedef union			u_box
{
	long long int			ll_int;
	unsigned long long int	u_ll_int;
}						t_data;

typedef struct	s_flag
{
	char	converter;
	va_list *ap;
	t_data	data;
	BOOL	point;
	BOOL	zero;
	BOOL	arg_neg;
	PAD_DIR padding_direction;
	int		len_padding;
	int		len_precision;
	int		lenght_modif;
}				t_flag;


enum			e_size
{
	HH = sizeof(char),
	H = sizeof(short int),
	L = sizeof(long int),
	LL = sizeof(long long int)
};

#endif