/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:17:52 by mravily           #+#    #+#             */
/*   Updated: 2020/01/04 03:17:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int		i;
	int		j;

	puts("============================================");
	puts("================ FLAGS TEST ================");
	puts("============================================");
	puts("================= ll DIGIT =================");
	puts("============================================");
	i = printf("|%lld|\n", (long long)12345679);
	j = ft_printf("|%lld|\n", (long long)12345679);
	printf("%d |%lld|\n", i, (long long)12345679);
	ft_printf("%d |%lld|\n", j, (long long)12345679);
	puts("=============== ll NEG DIGIT ===============");
	puts("============================================");
	i = printf("|%lld|\n", (long long)-12345679);
	j = ft_printf("|%lld|\n", (long long)-12345679);
	printf("%d |%lld|\n", i, (long long)-12345679);
	ft_printf("%d |%lld|\n", j, (long long)-12345679);
	puts("==================== ll x ==================");
	puts("============================================");
	i = printf("|%llx|\n", (long long)6262);
	j = ft_printf("|%llx|\n", (long long)6262);
	printf("%d |%llx|\n", i, (long long)6262);
	ft_printf("%d |%llx|\n", j, (long long)6262);
	puts("================== ll x NEG ================");
	puts("============================================");
	i = printf("|%llx|\n", (long long)-6262);
	j = ft_printf("|%llx|\n", (long long)-6262);
	printf("%d |%llx|\n", i, (long long)-6262);
	ft_printf("%d |%llx|\n", j, (long long)-6262);
	puts("==================== ll X ==================");
	puts("============================================");
	i = printf("|%llX|\n", (long long)6262);
	j = ft_printf("|%llX|\n", (long long)6262);
	printf("%d |%llX|\n", i, (long long)6262);
	ft_printf("%d |%llX|\n", j, (long long)6262);
	puts("================== ll X NEG ================");
	puts("============================================");
	i = printf("|%llX|\n", (long long)-6262);
	j = ft_printf("|%llX|\n", (long long)-6262);
	printf("%d |%llX|\n", i, (long long)-6262);
	ft_printf("%d |%llX|\n", j, (long long)-6262);
	puts("=================== ll u ===================");
	puts("============================================");
	i = printf("|%llu|\n", (long long)165142);
	j = ft_printf("|%llu|\n", (long long)165142);
	printf("%d |%llu|\n", i, (long long)165142);
	ft_printf("%d |%llu|\n", j, (long long)165142);
	puts("============================================");
	puts("================= ll NEG u =================");
	puts("============================================");
	i = printf("|%llu|\n", (long long)-165142);
	j = ft_printf("|%llu|\n",(long long)-165142);
	printf("%d |%llu|\n", i, (long long)-165142);
	ft_printf("%d |%llu|\n", j, (long long)-165142);
	return (0);
}