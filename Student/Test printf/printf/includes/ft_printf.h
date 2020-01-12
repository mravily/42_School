/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:36:45 by mravily           #+#    #+#             */
/*   Updated: 2020/01/04 03:45:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_basic.h"

enum			e_dir
{
	right = 0,
	left = 1
};

typedef union	u_box
{
	long long int			ll_int;
	unsigned long long int	u_ll_int;
}				t_data;

typedef struct	s_flag
{
	char			converter;
	va_list			*arg;
	t_data			data;
	enum e_bool		digit;
	enum e_bool		point;
	enum e_bool		zero;
	enum e_bool		arg_neg;
	enum e_bool		pre_size;
	enum e_bool		astrx;
	enum e_dir		padding_direction;
	int				len_padding;
	int				len_precision;
	int				lenght_modif;
}				t_flag;

enum			e_size
{
	HH = sizeof(char),
	H = sizeof(short int),
	L = sizeof(long int),
	LL = sizeof(long long int)
};

typedef struct	s_buffer
{
	char	to_print[400];
	int		len;
	int		total_len;
	int		max_size;
	t_flag	flag;
}				t_buffer;

t_buffer		create_buffer(int max_size);
t_buffer		*malloc_buffer(int max_size);
void			add_str(t_buffer *print, char *str);
void			add_char(t_buffer *print, char c);
void			print_text(t_buffer *print);

t_flag			create_t_flag(va_list *arg);
t_flag			*malloc_t_flag(va_list *arg);

void			print_flag(t_flag *flag);
void			reset_t_flag(t_flag *flag);

typedef void	(*t_convert_funct)(t_flag *flag, t_buffer *buffer);
typedef size_t	(*t_flag_funct)(const char *, size_t, t_flag *);

void			set_funct_convert_tab(t_convert_funct *funct_ptr);
void			add_padding(char **result, t_flag *flag, int len);
void			add_padding_digit(char **result, t_flag *flag, int len_arg);
void			converter_digit(t_flag *flag, t_buffer *buffer);
void			converter_str(t_flag *flag, t_buffer *buffer);
void			converter_c(t_flag *flag, t_buffer *buffer);
char			*ft_print_addr(void *ptr, char *base);
char			*ft_convert_value_to_base(char *base, t_flag *flag);
void			handle_x_converter(t_flag *flag, t_buffer *buffer);
void			handle_hexa_converter(t_flag *flag, t_buffer *buffer);
void			handle_addr_converter(t_flag *flag, t_buffer *buffer);
void			handle_unsigned_converter(t_flag *flag, t_buffer *buffer);

void			set_funct_flag_tab(t_flag_funct *funct_ptr);
size_t			check_flag_point(const char *format, size_t index,
t_flag *flag);
size_t			check_flag_minus(const char *format, size_t index,
t_flag *flag);
size_t			check_flag_zero(const char *format, size_t index, t_flag *flag);
size_t			handle_numeric_value_flag(const char *format, size_t index,
t_flag *flag);
size_t			check_flag_len_padding(const char *format, size_t index,
t_flag *flag);
size_t			check_flag_len_precision(const char *format, size_t index,
t_flag *flag);
size_t			check_flag_asterisk(const char *format, size_t index,
t_flag *flag);
size_t			prefix_size(const char *format, size_t index,
t_flag *flag);
void			resize_arg(t_flag *flag);

int				ft_printf(const char *format, ...);

#endif
