#include "ft_printf.h"

int main()
{	
	int nb = 42;
	puts("============================================");
	puts("================= MIX TEST =================");
	puts("============================================");
	puts("================== TEST 1 ==================");
	printf("-- %d --|\n", printf("|%-*p|", 16, NULL));
	ft_printf("-- %d --|\n", ft_printf("|%-*p|", 16, NULL));
	puts("================== TEST 2 ==================");
	printf("-- %d --|\n", printf("||%*p|", 16, NULL));
	ft_printf("-- %d --|\n", ft_printf("||%*p|", 16, NULL));
	puts("================== TEST 3 ==================");
	printf("-- %d --|\n", printf("|%-27p|", NULL));
	ft_printf("-- %d --|\n", ft_printf("|%-27p|", NULL));
	puts("================== TEST 4 ==================");
	printf("-- %d --|\n", printf("|%24p.0|", NULL));
	ft_printf("-- %d --|\n", ft_printf("|%24p.0|", NULL));
	puts("================== TEST 5 ==================");
	printf("-- %d --|\n", printf("|%*p|", -17, NULL));
	ft_printf("-- %d --|\n", ft_printf("|%*p|", -17, NULL));
	puts("================== TEST 6 ==================");
	printf("-- %d --|\n", printf("|%-*p|", -16, NULL));
	ft_printf("-- %d --|\n", ft_printf("|%-*p|", -16, NULL));
	puts("================== TEST 7 ==================");
	printf("-- %d --|\n", printf("|%-27p|", &nb));
	ft_printf("-- %d --|\n", ft_printf("|%-27p|", &nb));
	puts("================== TEST 8 ==================");
	printf("-- %d --|\n", printf("|%-*p|", -16, &nb));
	ft_printf("-- %d --|\n", ft_printf("|%-*p|", -16, &nb));
	puts("================== TEST 9 ==================");
	printf("-- %d --|\n", printf("|%14p|", &nb));
	ft_printf("-- %d --|\n", ft_printf("|%14p|", &nb));
	puts("================== TEST 10 ==================");
	printf("-- %d --|\n", printf("|%*p|", 10, &nb));
	ft_printf("-- %d --|\n", ft_printf("|%*p|", 10, &nb));
	puts("================== TEST 11 ==================");
	printf("-- %d --|\n", printf("|%24p|", &nb));
	ft_printf("-- %d --|\n", ft_printf("|%24p|", &nb));

	while (1) {}
	return (0);
}
