#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "ft_printf_basic.h"

enum e_dir
{
	right = 0,
	left = 1
};

# define PAD_DIR enum e_dir
# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)

typedef struct	s_flag
{
	va_list *arg;

	BOOL point;
	BOOL zero;
	BOOL arg_neg;
	PAD_DIR padding_direction;
	int len_padding;
	int len_precision;
}				t_flag;

t_flag create_t_flag(va_list *arg);
t_flag *malloc_t_flag(va_list *arg);

void print_flag(t_flag *flag);

typedef char * (*t_convert_funct)(t_flag *flag);
typedef size_t (*t_flag_funct)(char *, size_t, t_flag *);

// --- CONVERT PART
void	set_funct_convert_tab(t_convert_funct *funct_ptr);
void	ft_padding(char **result, BOOL to_test, int len, PAD_DIR direction);
char	*converter_d_i(t_flag *flag);
char	*converter_str(t_flag *flag);
char	*converter_c(t_flag *flag);

// --- FLAG PART
void set_funct_flag_tab(t_flag_funct *funct_ptr);
size_t check_flag_point(char *format, size_t index, t_flag *flag);
size_t check_flag_minus(char *format, size_t index, t_flag *flag);
size_t check_flag_zero(char *format, size_t index, t_flag *flag);
size_t handle_numeric_value_flag(char *format, size_t index, t_flag *flag);
size_t check_flag_len_padding(char *format, size_t index, t_flag *flag);
size_t check_flag_len_precision(char *format, size_t index, t_flag *flag);
size_t check_flag_asterisk(char *format, size_t index, t_flag *flag);

// --- PRINTF
int ft_printf(char *format, ...);

#endif
