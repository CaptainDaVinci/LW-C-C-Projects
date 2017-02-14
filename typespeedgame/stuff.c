#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void stcl()
{
	system("clear");
}

void anicel(int streak)
{

	//text position
	int tx, ty, a, b, e;
	tx = ty = a = b = e = 0;

	//loop for 20 times
	for(a = 0; a < 20; a++)
	{
		//positioning
		ty = a;
		tx++;
		e = b = 0;

		//printing
		stcl();
		printf("=========================================\n");

		while(e < ty)
		{
			printf(" \n");
			e++;
		}
		while(b < tx)
		{
			printf(" ");
			b++;
		}
		printf("You reached streak %d!\n", streak);
		printf("=========================================\n");
		usleep(100000);
	}

	stcl();
}
