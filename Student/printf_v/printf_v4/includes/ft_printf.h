#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "ft_printf_basic.h"

enum e_dir
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
	va_list *arg;
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

typedef struct	s_buffer
{
	char to_print[400];
	int len;
	int total_len;
	int max_size;
	t_flag flag;
}				t_buffer;

t_buffer create_buffer(int max_size);
t_buffer *malloc_buffer(int max_size);
void add_str(t_buffer *print, char *str);
void add_char(t_buffer *print, char c);
void print_text(t_buffer *print);

t_flag create_t_flag(va_list *arg);
t_flag *malloc_t_flag(va_list *arg);

void 	print_flag(t_flag *flag);
void	reset_t_flag(t_flag *flag);

typedef void	(*t_convert_funct)(t_flag *flag, t_buffer *buffer);
typedef size_t	(*t_flag_funct)(const char *, size_t, t_flag *);

// --- CONVERT PART
void	set_funct_convert_tab(t_convert_funct *funct_ptr);
void	add_padding(char **result, BOOL to_test, int len, PAD_DIR direction);
void 	converter_d_i(t_flag *flag, t_buffer *buffer);
void 	converter_str(t_flag *flag, t_buffer *buffer);
void 	converter_c(t_flag *flag, t_buffer *buffer);
char	*ft_convert_value_to_base(char *base, t_flag *flag);
void 	handle_x_X_converter(t_flag *flag, t_buffer *buffer);

// --- FLAG PART
void 	set_funct_flag_tab(t_flag_funct *funct_ptr);
size_t 	check_flag_point(const char *format, size_t index, t_flag *flag);
size_t 	check_flag_minus(const char *format, size_t index, t_flag *flag);
size_t 	check_flag_zero(const char *format, size_t index, t_flag *flag);
size_t 	handle_numeric_value_flag(const char *format, size_t index, t_flag *flag);
size_t 	check_flag_len_padding(const char *format, size_t index, t_flag *flag);
size_t 	check_flag_len_precision(const char *format, size_t index, t_flag *flag);
size_t 	check_flag_asterisk(const char *format, size_t index, t_flag *flag); 
void	resize_arg(t_flag *flag);

// --- PRINTF
int ft_printf(const char *format, ...);

#endif
