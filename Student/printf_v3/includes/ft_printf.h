/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:45:28 by mravily           #+#    #+#             */
/*   Updated: 2019/12/18 10:53:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

/* ********************** TEST *********************** */
# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# define PRINT_I printf("i = %zu\n", i)
# define PRINT_IW printf("i_w = %zu\n", *i)
# define PRINT_CIW printf("ci_w = [%c]\n", format[*i])
# define PRINT_0 printf("len_zero = %d\n", t_box->len_zero)
# define PRINT_PD printf("pad_dir = %d\n", t_box->pad_dir)
# define PRINT_FIELD printf("len_field = %d\n", t_box->len_field_width)
# define PRINT_PREC	printf("len_prec = %d\n", t_box->len_precis)
# define PRINT_PAD	printf("len_pad = %d\n", t_box->len_pad)
# define LEN_ARG printf("len_arg = %d\n", len_arg)
# define LEN_PREC printf("len_prec = %d\n", len_precis)
# define LEN_ATX printf("len_astx = %d\n", len_asterix)
# define LEN_PAD printf("len_padding = %d\n", len_padding)
# define LEN_PRINT printf("len_print = %d\n", len_to_print)
# define LEN_FIELD printf("len_field = %d\n", len_field_width)

/* ************************************************** */

# define LEFT 1
# define RIGHT 0
# define TRUE 1
# define FALSE 0


typedef struct	s_box
{

	int		printed_char;
	int		pad_dir;
	int		f_space;
	int		f_zero;
	int		f_precis;
	int		len_pad;
	int		len_precis;
	int		c_digit;
	int		c_char;
	int		convert_sign;
	
	int		f_asterisk;
	int		f_field_width;
	int		lenght_modif;
	
}				t_tool_box;

typedef union			u_box
{
	long long int			ll_int;
	unsigned long long int	u_ll_int;
}						t_data;

enum			e_box
{
	HH = sizeof(char),
	H = sizeof(short int),
	L = sizeof(long int),
	LL = sizeof(long long int)
};

int			ft_printf(const char *format, ...);
int			ft_isdigit(int c);
int			ft_strlen(char *str);
char		*ft_printchar(int c);
char		*ft_printstr(char *str);
int			ft_atoi_index(const char *str);
void		ft_reset_flags(t_tool_box *t_box);
char		*ft_print_addr(void *ptr, char *base);
char		*ft_itoa(t_data *data);
void		ft_print_arg(t_tool_box *t_box, char *arg);
void		ft_print_arg_str(t_tool_box *t_box, char *arg);
void		ft_print_arg_addr(t_tool_box *t_box, char *arg);
void		ft_padding_right(t_tool_box *t_box, char *arg);
void		ft_padding_left(t_tool_box *t_box, int i, long int len_arg);
void		ft_resize_arg(t_data *data, va_list *ap, t_tool_box *t_box);
void		ft_get_padding(t_tool_box *t_box, const char *format, size_t *i);
void		ft_padding_zero(t_tool_box *t_box, char *arg, int *i);
void		ft_print_precise(t_tool_box *t_box, char *arg,
int i, long int len);
void		ft_parsing(const char *format, va_list *ap, size_t *i,
t_tool_box *t_box);
char		*ft_convert_value_to_base(t_data *data, char *base,
t_tool_box *t_box);



#endif