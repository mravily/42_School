#include <stdio.h>
#include <string.h>

int		main(void)
{
	const char s[] = {"It's a const string for test function"};

	puts(strrchr(s,'r'));
}
