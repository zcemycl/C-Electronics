#include <stdio.h>
#include <time.h>

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void main()
{
	int i;
	while (1)
	{
		printf("\rloop %d",i);
		delay(1000000);
		fflush(stdout);
		i++;
	}
}
