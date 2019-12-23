/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:41:20 by mravily           #+#    #+#             */
/*   Updated: 2019/12/23 13:26:35 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	create_t_flag(t_flag *flag, va_list *arg)
{
	
	flag->ap = arg;
	flag->point = false;
	flag->zero = false;
	flag->padding_direction = right;
	flag->len_padding = -1;
	flag->len_precision = -1;
	flag->lenght_modif = -1;

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

size_t		parse_flag(const char *format, size_t index, t_flag *flag)
{
	static char funct_flag[127] = {NULL};
	size_t	flag_len;
	
	if (funct_flag[0] == NULL)
		set_convert_flag_tab(&funct_flag);
	index++;
	flag_len = 0;
	while (ft_strcmp_c(".-0123456789", format[index]) == true)
		flag_len += funct_flag[format[index + flag_len]];
	flag->converter = format[index + flag_len];
	return (flag_len + 1);
}
void		parse_convert(t_flag flag)
{
	static char *funct_convert[127] = {NULL};
	char		c;

	if (funct_convert[0] == NULL)
		set_funct_convert_tab(&funct_convert);
	c = flag.converter;
	if (funct_convert[c] != NULL)
		funct_convert[c]
	
}
int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flag		flag;
	int			index;
	size_t		flag_len;
	int			c;

	va_start(ap, format);
	create_t_flag(&flag, &ap);

	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			flag_len = parse_flag(format, index, &flag);
			c = flag.converter;
			parse_convert(flag);
		}
		else 
		{
			
		}
		index++;
	}
	return ()
}