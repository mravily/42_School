#include "ft_printf.h"

int main()
{	
	puts("============================================");
	puts("================= MIX TEST =================");
	puts("============================================");
	puts("================== TEST 1 ==================");
	printf("-- %d --|\n", printf("|a%-i vzZUl6IUs%1.5s%-s", 2147483647, "", NULL));
	ft_printf("-- %d --|\n", ft_printf("|a%-i vzZUl6IUs%1.5s%-s", 2147483647, "", NULL));
	puts("================== TEST 2 ==================");
	printf("-- %d --|\n", printf("|%019dZ6j2hpZNiLDHnaNMci%%e1FT|", -41975835));
	ft_printf("-- %d --|\n", ft_printf("|%019dZ6j2hpZNiLDHnaNMci%%e1FT|", -41975835));
	puts("================== TEST 3 ==================");
	printf("-- %d --|\n", printf("|%-12s%12cq4ko", NULL, '\0'));
	ft_printf("-- %d --|\n", ft_printf("|%-12s%12cq4ko", NULL, '\0'));
	puts("================== TEST 4 ==================");
	printf("-- %d --|\n", printf("|%.*s%%|", 8, ""));
	ft_printf("-- %d --|\n", ft_printf("|%.*s%%|", 8, ""));
	puts("================== TEST 5 ==================");
	printf("-- %d --|\n", printf("|ufyB%2chN", '\0'));
	ft_printf("-- %d --|\n", ft_printf("|ufyB%2chN", '\0'));
	puts("================== TEST 6 ==================");
	printf("-- %d --|\n", printf("|%*c%-.4do8PB4pmnpcPBOP%uf3L5gL8URYL%c", -2, '\0', 0, 2147483647, '\0'));
	ft_printf("-- %d --|\n", ft_printf("|%*c%-.4do8PB4pmnpcPBOP%uf3L5gL8URYL%c", -2, '\0', 0, 2147483647, '\0'));
	puts("================== TEST 7 ==================");
	printf("-- %d --|\n", printf("|%-u%*s|", 843045459, -2, ""));
	ft_printf("-- %d --|\n", ft_printf("|%-u%*s|", 843045459, -2, ""));
	puts("================== TEST 9 ==================");
	printf("-- %d --|\n", printf("|motuGRlqqLD4M4V%cBt%-9s", 'z', NULL));
	ft_printf("-- %d --|\n", ft_printf("|motuGRlqqLD4M4V%cBt%-9s", 'z', NULL));
	puts("================== TEST 10 ==================");
	printf("-- %d --|\n", printf("|%-*XIWp7%%%*.5s", -6, -2039661669, -4, NULL));
	ft_printf("-- %d --|\n", ft_printf("|%-*XIWp7%%%*.5s", -6, -2039661669, -4, NULL));
	puts("================== TEST 11 ==================");
	printf("-- %d --|\n", printf("|%5.1s%0upB3eRFVO|", NULL, -2147483647));
	ft_printf("-- %d --|\n", ft_printf("|%5.1s%0upB3eRFVO|", NULL, -2147483647));
	puts("================== TEST 12 ==================");
	printf("-- %d --|\n", printf("|4yhu%-13.2swbSw1|", NULL));
	ft_printf("-- %d --|\n", ft_printf("|4yhu%-13.2swbSw1|", NULL));
	puts("================== TEST 13 ==================");
	printf("-- %d --|\n", printf("|Tv%0*u%-11.0s%-urVA%-.2s%X|", 9, 2147483647, NULL, 0, "", 2147483647));
	ft_printf("-- %d --|\n", ft_printf("|Tv%0*u%-11.0s%-urVA%-.2s%X|", 9, 2147483647, NULL, 0, "", 2147483647));
	puts("================== TEST 14 ==================");
	printf("-- %d --|\n", printf("|NYl9J%-4cFh5uH%-7u%-14XeFs%3.4s%-20.4sPfPzi|", 'C', -2147483647, 822061092, "", NULL));
	ft_printf("-- %d --|\n", ft_printf("|NYl9J%-4cFh5uH%-7u%-14XeFs%3.4s%-20.4sPfPzi|", 'C', -2147483647, 822061092, "", NULL));
	puts("================== TEST 15 ==================");
	printf("-- %d --|\n", printf("|%.s%-2.4x%-.4s%0*X%13.3slk0oA3Dkzp3Ew", "q5q4853LH|", -2147483647, "VAk5ac", 9, -2147483647, ""));
	ft_printf("-- %d --|\n", ft_printf("|%.s%-2.4x%-.4s%0*X%13.3slk0oA3Dkzp3Ew", "q5q4853LH|", -2147483647, "VAk5ac", 9, -2147483647, ""));
	puts("================== TEST 15 ==================");
	printf("-- %d --|\n", printf("|%.s%-2.4x%-.4s%0*X%13.3slk0oA3Dkzp3Ew", "q5q4853LH|", -2147483647, "VAk5ac", 9, -2147483647, ""));
	ft_printf("-- %d --|\n", ft_printf("|%.s%-2.4x%-.4s%0*X%13.3slk0oA3Dkzp3Ew", "q5q4853LH|", -2147483647, "VAk5ac", 9, -2147483647, ""));
	puts("================== TEST 16 ==================");
	printf("-- %d --|\n", printf("|wD6Ie7T46rk1|%.*s|", -1, "u LANPTGSF b9"));
	ft_printf("-- %d --|\n", ft_printf("|wD6Ie7T46rk1|%.*s|", -1, "u LANPTGSF b9"));
	puts("================== TEST 17 ==================");
	printf("-- %d --|\n", printf("|FpjLs%-2.4s%c%dlRxW6J6lKCH0lrhMCu%-.5X|", NULL, 'a', 2147483647, 0));
	ft_printf("-- %d --|\n", ft_printf("|FpjLs%-2.4s%c%dlRxW6J6lKCH0lrhMCu%-.5X|", NULL, 'a', 2147483647, 0));
	while (1) {}
	return (0);
	
}
