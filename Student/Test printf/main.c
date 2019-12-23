#include "ft_printf.h"

int main()
{	
	/*
	puts("============================================");
	puts("================= MIX TEST =================");
	puts("============================================");
	puts("================== TEST 1 ==================");
	printf("-- %d --|\n", printf("|%17d LVcGOj2a0d86O|", -2147483647));
	//                            0123456789 ----- 14 -----
	ft_printf("-- %d --|\n", ft_printf("|%17d LVcGOj2a0d86O|", -2147483647));
	//                                  0123456789
	puts("================== TEST 2 ==================");
	printf("-- %d --|\n", printf("|%-*c|", -10, 'o'));
	//                            012345
	ft_printf("-- %d --|\n", ft_printf("|%-*c|", -10, 'o'));
	puts("================== TEST 3 ==================");
	printf("-- %d --|\n", printf("|%-*.0d|", -1, 2147483647));
	ft_printf("-- %d --|\n", ft_printf("|%-*.0d|", -1, 2147483647));
	//                                 	012345678911
	puts("================== TEST 4 ==================");
	printf("-- %d --|\n", printf("|hjD%5XuX|", -2147483647));
	ft_printf("-- %d --|\n", ft_printf("|hjD%5XuX|", -2147483647));
	//                                 	0123456789
	puts("================== TEST 5 ==================");
	printf("-- %d --|\n", printf("|06 yx%12c%9c6V2ZF%-14i%-*s|", 'U', '\0', -2147483647, -3, ""));
	ft_printf("-- %d --|\n", ft_printf("|06 yx%12c%9c6V2ZF%-14i%-*s|", 'U', '\0', -2147483647, -3, ""));
	//                                 	0123456789
	puts("================== TEST 6 ==================");
	printf("-- %d --|\n", printf("|%-10.5s%.2d|", "", 1315724962));
	ft_printf("-- %d --|\n", ft_printf("|%-10.5s%.2d|", "", 1315724962));
	//                                 	0123456789
	puts("================== TEST 7 ==================");
	printf("-- %d --|\n", printf("|%0xVkgho%20.*sFbhuJYwdx|", 1901203325, -2, ""));
	ft_printf("-- %d --|\n", ft_printf("|%0xVkgho%20.*sFbhuJYwdx|", 1901203325, -2, ""));
	//                                 	0123456789
	puts("================== TEST 8 ==================");
	printf("-- %d --|\n", printf("|Xwcx%-x4Xq%-17.1sTC141qBJRIWzeckFX1UP|", -2147483647, NULL));
	ft_printf("-- %d --|\n", ft_printf("|Xwcx%-x4Xq%-17.1sTC141qBJRIWzeckFX1UP|", -2147483647, NULL));
	//                                 	0123456789
	puts("================== TEST 9 ==================");
	printf("-- %d --|\n", printf("|5y9Uo4xTT6Me8vljSDrAIZIb9NNS%8.2s|", NULL));
	ft_printf("-- %d --|\n", ft_printf("|5y9Uo4xTT6Me8vljSDrAIZIb9NNS%8.2s|", NULL));
	//                                 	0123456789
	puts("================= TEST 10 ==================");
	printf("-- %d --|\n", printf("|tJpY%11.3sw20R%%FzDc|", NULL));
	ft_printf("-- %d --|\n", ft_printf("|tJpY%11.3sw20R%%FzDc|", NULL));
	//                                 	0123456789
	puts("================= TEST 11 ==================");
	*/
	printf("-- %d --|\n", printf("|%0*.0x|", 5, 0));
	ft_printf("-- %d --|\n", ft_printf("|%0*.0x|", 5, 0));
	//                                 	0123456789
	printf("-- %d --|\n", printf("|%0*.0x%12cQO%01u%0us9Jue%.4d8OZ|", 5, 0, '3', 2147483647, 2147483647, 2147483647));
	ft_printf("-- %d --|\n", ft_printf("|%0*.0x%12cQO%01u%0us9Jue%.4d8OZ|", 5, 0, '3', 2147483647, 2147483647, 2147483647));
	return (0);
}
