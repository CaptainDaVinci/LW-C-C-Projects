#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "play.h"

/*
* This Project is made for linux. To make this compatible with windows
* change clear to cls in the stcl() function in stuff.c
*/

//main method
int main(void)
{
	game = malloc(sizeof(*game));

	//welcome message
	stcl();
	printf("\n\n");
	printf("==============================\n");
	printf("           Welcome!           \n");
	printf("     to type speed racer      \n");
	printf("==============================\n");

	//options before play
	printf("\nChange settings first before starting game (recommendation)!\n");

	int option = 2; // option id 1 defaults to 2

	while(true)
	{
		printf("\n1) Start Game\n2) Settings\n3) Exit\n\n> ");
		scanf("%i", &option);
		printf("\n");

		switch(option)
		{
			case 1: play(game);
					break;

			case 2: settings(game);
					break;

			case 3: exit(0);

			default: printf("\nInvalid Option!\n");
					 break;
		}
	}

	free(game);
}
