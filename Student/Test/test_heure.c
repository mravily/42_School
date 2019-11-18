#include <stdio.h>
#include <stdlib.h>

void decoupeMinutes(int *heures, int *minutes);

int main(int argc, char *argv[])
{
    int heures;
	int minutes;

	heures = 0;
	minutes = 90;

    decoupeMinutes(&heures, &minutes);

    printf("%d heures et %d minutes", heures, minutes);

    return 0;
}

void decoupeMinutes(int *p_sur_heures, int *p_sur_minutes)
{
    *p_sur_heures = *p_sur_minutes / 60;  // 90 / 60 = 1
    *p_sur_minutes %=  60; // 90 % 60 = 30
}