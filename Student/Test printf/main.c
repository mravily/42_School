#include "ft_printf.h"

// int main()
// {
// 	puts("============================================");
// 	puts("================= MIX TEST =================");
// 	puts("============================================");
// 	puts("================== TEST 1 ==================");
// 	printf("-- %d --|\n", printf("|%17d LVcGOj2a0d86O|", -2147483647));
// 	//                            0123456789 ----- 14 -----
// 	ft_printf("-- %d --|\n", ft_printf("|%17d LVcGOj2a0d86O|", -2147483647));
// 	//                                  0123456789
// 	puts("================== TEST 2 ==================");
// 	printf("-- %d --|\n", printf("|%-*c|", -10, 'o'));
// 	//                            012345
// 	ft_printf("-- %d --|\n", ft_printf("|%-*c|", -10, 'o'));
// 	puts("================== TEST 3 ==================");
// 	printf("-- %d --|\n", printf("|%-*.0d|", -1, 2147483647));
// 	ft_printf("-- %d --|\n", ft_printf("|%-*.0d|", -1, 2147483647));
// 	//                                 	012345678911
// 	puts("================== TEST 4 ==================");
// 	printf("-- %d --|\n", printf("|hjD%5XuX|", -2147483647));
// 	ft_printf("-- %d --|\n", ft_printf("|hjD%5XuX|", -2147483647));
// 	//                                 	0123456789
// 	puts("================== TEST 5 ==================");
// 	printf("-- %d --|\n", printf("|06 yx%12c%9c6V2ZF%-14i%-*s|", 'U', '\0', -2147483647, -3, ""));
// 	ft_printf("-- %d --|\n", ft_printf("|06 yx%12c%9c6V2ZF%-14i%-*s|", 'U', '\0', -2147483647, -3, ""));
// 	//                                 	0123456789
// 	puts("================== TEST 6 ==================");
// 	printf("-- %d --|\n", printf("|%-10.5s%.2d|", "", 1315724962));
// 	ft_printf("-- %d --|\n", ft_printf("|%-10.5s%.2d|", "", 1315724962));
// 	//                                 	0123456789
// 	puts("================== TEST 7 ==================");
// 	printf("-- %d --|\n", printf("|%0xVkgho%20.*sFbhuJYwdx|", 1901203325, -2, ""));
// 	ft_printf("-- %d --|\n", ft_printf("|%0xVkgho%20.*sFbhuJYwdx|", 1901203325, -2, ""));
// 	//                                 	0123456789
// 	puts("================== TEST 8 ==================");
// 	printf("-- %d --|\n", printf("|Xwcx%-x4Xq%-17.1sTC141qBJRIWzeckFX1UP|", -2147483647, NULL));
// 	ft_printf("-- %d --|\n", ft_printf("|Xwcx%-x4Xq%-17.1sTC141qBJRIWzeckFX1UP|", -2147483647, NULL));
// 	//                                 	0123456789
// 	puts("================== TEST 9 ==================");
// 	printf("-- %d --|\n", printf("|5y9Uo4xTT6Me8vljSDrAIZIb9NNS%8.2s|", NULL));
// 	ft_printf("-- %d --|\n", ft_printf("|5y9Uo4xTT6Me8vljSDrAIZIb9NNS%8.2s|", NULL));
// 	//                                 	0123456789
// 	puts("================= TEST 10 ==================");
// 	printf("-- %d --|\n", printf("|tJpY%11.3sw20R%%FzDc|", NULL));
// 	ft_printf("-- %d --|\n", ft_printf("|tJpY%11.3sw20R%%FzDc|", NULL));
// 	//                                 	0123456789
// 	puts("================= TEST 11 ==================");
// 	printf("-- %d --|\n", printf("|%0*.0x%12cQO%01u%0us9Jue%.4d8OZ|", 5, 0, '3', 2147483647, 2147483647, 2147483647));
// 	ft_printf("-- %d --|\n", ft_printf("|%0*.0x%12cQO%01u%0us9Jue%.4d8OZ|", 5, 0, '3', 2147483647, 2147483647, 2147483647));
// 	puts("================= TEST 12 ==================");
// 	printf("-- %d --|\n", printf("|%.*d|", -8, -1956738847));
// 	ft_printf("-- %d --|\n", ft_printf("|%.*d|", -8, -1956738847));
// 	puts("================= TEST 13 ==================");
// 	printf("-- %d --|\n", printf("|%0*d|", 5, -1));
// 	ft_printf("-- %d --|\n", ft_printf("|%0*d|", 5, -1));
// 	while (1) {}
// 	return (0);

// }

#include <time.h>

int generate_nbr(int min, int max)
{
	return ((rand() % (max + 1 - min)) + min);
}

int main()
{
	int nb_test = 100;

	enum e_bool minus;
	enum e_bool zero;
	enum e_bool point;
	enum e_bool wildcard1;
	enum e_bool wildcard2;
	int padding;
	int precision;

	char *test = "ceci est un test";
	char *cmd;

	srand(time(NULL));

	for (int i = 0; i < nb_test; i++)
	{
		minus = (generate_nbr(0, 1) == 0 ? false : true);
		zero = (generate_nbr(0, 1) == 0 ? false : true);
		point = (generate_nbr(0, 1) == 0 ? false : true);
		wildcard1 = (generate_nbr(0, 1) == 0 ? false : true);
		wildcard2 = (generate_nbr(0, 1) == 0 ? false : true);
		padding = generate_nbr(-10, 10);
		precision = generate_nbr(-10, 10);

		cmd = ft_strdup("[%");
		if (minus == true)
			ft_str_add_suffix(&cmd, "-");
		if (zero == true)
			ft_str_add_suffix(&cmd, "0");
		// if (wildcard1 == true)
		// 	ft_str_add_suffix(&cmd, "*");
		// else
			ft_str_add_suffix(&cmd, ft_itoa(padding));
		if (point == true)
		{
			// if (wildcard2 == true)
			// 	ft_str_add_suffix(&cmd, ".*");
			// else
			// {
				ft_str_add_suffix(&cmd, ".");
				ft_str_add_suffix(&cmd, ft_itoa(precision));
			// }
		}
		ft_str_add_suffix(&cmd, "s]");

		printf("==-== test with [%s] ==-==\n", cmd);
		// if (wildcard1 == false && wildcard2 == false)
		// {
			printf(" -> OUR  = %d\n", ft_printf(cmd, test));
			printf(" -> THEM = %d\n", printf(cmd, test));
		// }
		// else if (wildcard1 == true && wildcard2 == false)
		// {
		// 	printf(" -> OUR  = %d\n", ft_printf(cmd, padding, test));
		// 	printf(" -> THEM = %d\n", printf(cmd, padding, test));
		// }
		// else if (wildcard1 == false && wildcard2 == true)
		// {
		// 	printf(" -> OUR  = %d\n", ft_printf(cmd, precision, test));
		// 	printf(" -> THEM = %d\n", printf(cmd, precision, test));
		// }
		// else
		// {
		// 	printf(" -> OUR  = %d\n", ft_printf(cmd, padding, precision, test));
		// 	printf(" -> THEM = %d\n", printf(cmd, padding, precision, test));
		// }
	}

	return (0);

}
