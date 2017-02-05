#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "stuff.h"
#include "play.h"

/*
* This Project is made for linux. To make this compatible with windows
* change clear to cls in the stcl() function in stuff.c
*/

//main method
int main(void){
	//welcome message
	stcl();
	printf("\n\n");
	printf("==============================\n");
	printf("           Welcome!           \n");
	printf("     to type speed racer      \n");
	printf("==============================\n");

	//options before play
	printf("\nChange settings first before starting game (recommendation)!\n");

	while(true){
		printf("\n1) Start Game\n2) Settings\n3) Exit\n\n> ");
		int optid0 = 2; // option id 1 defaults to 2
		scanf("%i", &optid0);
		printf("\n");

		switch(optid0){ //test what option the user has chosen and does something
			case 1:
				play();
				break;

			case 2:
				settings();
				break;

			case 3:
				printf("\n\n");
				exit(0);
				break;

			default:
				printf("\nInvalid Option!\n");
				break;
		}
	}
	return 0;
}
