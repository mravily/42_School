/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:43:20 by mravily           #+#    #+#             */
/*   Updated: 2019/12/13 17:35:24 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define LEFT 1	
# define RIGHT 0
# define ERROR -1

typedef struct	s_box
{
	int	n_char_display;
	int	pad_dir;
	int	pad_zero;
	int pad_space;
	int len_padding;
	int len_precis;
	int	precision;
	int	asterix;
	int	arg_neg;
	int str_convert;
	int char_convert;
	int addr_convert;
	int hexa_convert;
	int len_space;
	int	digit;
	int	empty_str;
	int convert_sign;
	int	lenght;
}				t_tool_box;

typedef union 			u_box
{
	char            		char_;
	unsigned char 			u_char;
	short					s_int;
	unsigned short 			u_s_int;
	long int				l_int;
	unsigned long int		u_l_int;
	long long int			ll_int;
	unsigned long long int 	u_ll_int;
	intmax_t				intmax_;
	uintmax_t				uintmax_;
}						t_data;

enum			e_box
{
	HH = sizeof(char),
	H = sizeof(short int),
	L = sizeof(long int),
	LL = sizeof(long long int)
};

int				ft_printf(const char *format, ...);
void			ft_check_input(t_tool_box *t_box, const char *format, size_t *i, va_list *ap);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			ft_resize_arg_1(t_data *data, va_list *ap, t_tool_box *t_box);
void			ft_print_arg(t_tool_box *t_box, char *arg);
void			ft_reset_flag(t_tool_box *t_box);
void			ft_padding(t_tool_box *t_box, int len_arg);
char			*ft_printchar(int c);
char			*ft_printstr(char *str, t_tool_box *t_box);
void			ft_print_arg_addr(t_tool_box *t_box, char *arg);
char			*ft_print_addr(void *ptr, char *base);
char			*ft_itoa(t_data *data, t_tool_box *t_box);
char			*ft_convert_value_to_base(t_data *data, char *base, t_tool_box *t_box);
size_t			ft_strlen(char *str);
size_t			ft_int_len(int nb);

# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)

#endif
