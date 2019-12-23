#include "../includes/ft_printf.h"

t_flag create_t_flag(va_list *arg)
{
	t_flag result;

	result.arg = arg;
	result.point = false;
	result.zero = false;
	result.padding_direction = right;
	result.len_padding = -1;
	result.len_precision = -1;
	result.lenght_modif = -1;

	return (result);
}

t_flag *malloc_t_flag(va_list *arg)
{
	t_flag *result;

	result = (t_flag *)malloc(sizeof(t_flag));
	if (result == NULL)
		return (NULL);

	*result = create_t_flag(arg);

	return (result);
}

void	reset_t_flag(t_flag *flag)
{
	flag->point = false;
	flag->zero = false;
	flag->padding_direction = right;
	flag->len_padding = -1;
	flag->len_precision = -1;
	flag->lenght_modif = -1;
}

void print_flag(t_flag *flag)
{
	printf("\n===============\n");
	printf("=State of flag=\n");
	printf("Point : %s\n", (flag->point == true ? "true" : "false"));
	printf("Zero : %s\n", (flag->zero == true ? "true" : "false"));
	printf("Dir : %s\n", (flag->padding_direction == right ? "right" : "left"));
	printf("Len_pading : %d\n", flag->len_padding);
	printf("Len_precision : %d\n", flag->len_precision);
	printf("converter = %c\n", flag->converter);
	printf("===============\n");
}
