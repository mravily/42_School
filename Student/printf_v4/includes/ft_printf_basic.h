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

void		ft_str_add_prefixe(char *p_prefixe, char **p_str);
void		ft_str_add_suffix(char **p_str, char *p_suffix);
char		*ft_strcpy(char *p_src, char *p_dest);
char		*ft_strdup(char *p_src);
char		*ft_strdup_c(char p_src);
char		*ft_strjoin(char *p_str1, char *p_str2);
size_t		ft_strlen(char *p_src);
char		*ft_strnew(size_t p_len);
char		*ft_strnew_c(size_t p_len, char c);
char		*ft_strsub(char *p_src, size_t p_start, size_t p_len);
BOOL		ft_strcmp_c(char *p_src, char p_target);

int			ft_atoi(char *p_str);
float		ft_f_abs(float p_value);
float		ft_f_floor(float p_value);
float		ft_f_roof(float p_value);
int			ft_i_abs(int p_value);
int			ft_i_roof(float p_value);
char		*ft_itoa_base(long long int nbr, char *base);
char		*ft_itoa_hexa(long long int nbr);
char		*ft_itoa_octa(long long int nbr);
char		*ft_itoa_unsigned_deci(unsigned int nbr);
char		*ft_itoa(long long int nbr);

size_t		ft_nbrlen(long long int nbr, size_t base_len);

#endif
