/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:33:37 by tguilbar          #+#    #+#             */
/*   Updated: 2019/12/08 17:16:58 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*string;
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	int		fd7;
	int		fd8;
	int		fd9;
	int		fd10;
	int		fd11;
	int		fd12;
	int		fd13;
	int		fd14;
	int		fd15;
	int		fd16;
	int		fd17;
	int		ret;

	string = NULL;
	
		fd = open("63_line" ,O_RDONLY);
		fd1 = open("63_line_nl" ,O_RDONLY);
		fd2 = open("64_line" ,O_RDONLY);
		fd3 = open("64_line_nl" ,O_RDONLY);
		fd4 = open("65_line" ,O_RDONLY);
		fd5 = open("65_line_nl" ,O_RDONLY);
		fd6 = open("baudelaire.txt" ,O_RDONLY);
		fd7 = open("empty" ,O_RDONLY);
		fd8 = open("empty_one" ,O_RDONLY);
		fd9 = open("large_file.txt" ,O_RDONLY);
		fd10 = open("lorem_ipsum" ,O_RDONLY);
		fd11 = open("many_lines" ,O_RDONLY);
		fd12 = open("Mr. Justice Maxell by Edgar Wallace.txt" ,O_RDONLY);
		fd13 = open("multi_in_one" ,O_RDONLY);
		fd14 = open("one_big_fat_line.txt" ,O_RDONLY);
		fd15 = open("over_buffer" ,O_RDONLY);
		fd16 = open("simple" ,O_RDONLY);
		fd17 = 42;
		/*
		ret = 1;
		puts("==================== 63_line ===================");
		while (ret == 1)
		{
			ret = get_next_line(fd, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== 63_line_nl ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd1, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== ERROR_FILE ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd17, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("==================== 64_line ===================");
		while (ret == 1)
		{
			ret = get_next_line(fd2, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== 64_line_nl ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd3, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("==================== 65_line ===================");
		while (ret == 1)
		{
			ret = get_next_line(fd4, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== 65_line_nl ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd5, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== baudelaire.txt ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd6, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== empty ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd7, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== empty_one ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd8, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== large_file.txt ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd9, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		
		ret = 1;
		puts("=================== lorem_ipsum ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd10, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== many_lines ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd11, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== Mr. Justice Maxell by Edgar Wallace.txt ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd12, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== multi_in_one ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd13, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		*/
		ret = 1;
		puts("=================== one_big_fat_line.txt ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd14, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		/*
		ret = 1;
		puts("=================== over_buffer ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd15, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		ret = 1;
		puts("=================== simple ==================");
		while (ret == 1)
		{
			ret = get_next_line(fd16, &string);
			printf("%d | %s\n", ret, string);
			free(string);
		}
		*/
	while (1)
	{}
	return (0);
}
