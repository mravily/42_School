/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_multi_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:33:37 by tguilbar          #+#    #+#             */
/*   Updated: 2019/11/29 12:22:46 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
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
	int		ret1;
	int		ret2;
	int		ret3;
	int		ret4;
	int		ret5;
	int		ret6;
	int		ret7;
	int		ret8;
	int		ret9;
	

		fd1 = open("empty" ,O_RDONLY);
		fd2 = open("empty_one" ,O_RDONLY);
		fd3 = open("large_file.txt" ,O_RDONLY);
		fd4 = open("lorem_ipsum" ,O_RDONLY);
		fd5 = open("many_lines" ,O_RDONLY);
		fd6 = open("multi_in_one" ,O_RDONLY);
		fd7 = open("one_big_fat_line.txt" ,O_RDONLY);
		fd8 = open("over_buffer" ,O_RDONLY);
		fd9 = 42;
		/*
		ret1 = 1;
		ret2 = 1;
		ret3 = 1;
		puts("=================== Multi_FD TEST 1 ==================");
		while (ret1 == 1 || ret2 == 1 || ret3 == 1)
		{
			if (ret1 == 1)
			{
				ret1 = get_next_line(fd1, &string);
				printf("%d | %s | FILE 1\n", ret1, string);
				free(string);
			}
			if (ret2 == 1)
			{
				ret2 = get_next_line(fd4, &string);
				printf("%d | %s | FILE 2\n", ret2, string);
				free(string);
			}
			if (ret3 == 1)
			{
				ret3 = get_next_line(fd7, &string);
				printf("%d | %s | FILE 3\n", ret3, string);
				free(string);
			}
		}
		ret4 = 1; 
		ret5 = 1;
		ret6 = 1;
		puts("=================== Multi_FD TEST 2 ==================");
		while (ret4 == 1 || ret5 == 1 || ret6 == 1)
		{
			if (ret4 == 1)
			{
				ret4 = get_next_line(fd2, &string);
				printf("%d | %s | FILE 1\n", ret4, string);
				free(string);
			}
			if (ret5 == 1)
			{
				ret5 = get_next_line(fd5, &string);
				printf("%d | %s | FILE 2\n", ret5, string);
				free(string);
			}
			if (ret6 == 1)
			{
				ret6 = get_next_line(fd8, &string);
				printf("%d | %s | FILE 3\n", ret6, string);
				free(string);
			}
		*/
		ret7 = 1; 
		ret8 = 1;
		ret9 = 1;
		puts("=================== Multi_FD TEST 3 ==================");
		while (ret7 == 1 || ret8 == 1 || ret9 == 1)
		{
			if (ret7 == 1)
			{
				ret7 = get_next_line(fd3, &string);
				printf("%d | %s | FILE 1\n", ret7, string);
				free(string);
			}
			if (ret8 == 1)
			{
				ret8 = get_next_line(fd6, &string);
				printf("%d | %s | FILE 2\n", ret8, string);
				free(string);
			}
			if (ret9 == 1)
			{
				ret9 = get_next_line(fd9, &string);
				printf("%d | %s | FILE 3\n", ret9, string);
			}
		}
	return (0);
}
