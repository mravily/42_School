#include "../includes/ft_printf.h"

t_buffer create_buffer(int max_size)
{
	t_buffer result;
	int i;

	i = 0;
	while (i < 400)
	{
		result.to_print[i] = '\0';
		i++;
	}
	result.len = 0;
	result.total_len = 0;
	result.max_size = max_size;
	return (result);
}

t_buffer *malloc_buffer(int max_size)
{
	t_buffer *result;

	result = (t_buffer *)malloc(sizeof(t_buffer));
	if (result == NULL)
		return (NULL);

	*result = create_buffer(max_size);
	return (result);
}

void add_str(t_buffer *print, char *str)
{
	int i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (print->len >= print->max_size - 1)
		{
			write(1, print->to_print, print->max_size);
			print->len = 0;
		}
		
		print->to_print[print->len] = str[i];
		print->len++;
		print->total_len++;
		i++;
	}
}

void add_char(t_buffer *print, char c)
{

	if (print->len >= print->max_size - 1)
	{
		write(1, print->to_print, print->max_size);
		print->len = 0;
	}
		
	print->to_print[print->len] = c;
	print->len++;
	print->total_len++;
}

void print_text(t_buffer *print)
{
	write(1, print->to_print, print->len);
	print->len = 0;
}