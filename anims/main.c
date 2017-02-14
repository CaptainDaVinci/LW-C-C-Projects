#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "animations.h"

int main(void){
	int inpi;
	while(true){
		stcl();
		printf("Type 0 to exit.\n");
		printf("==========================\n"); // welcome message
		printf("#       Welcome to       #\n"); // welcome message
		printf("#    text animations!    #\n"); // welcome message
		printf("==========================\n"); // welcome message
		printf("1) Text TL to BR\n2) Text Bounce\n3) Building Characters\n4) Stripe\n"); // animations list
		printf("\n[>   ");
		scanf("%i", &inpi);
		printf("\n");
		switch(inpi){
			case 0:
				printf("\n\n");
				stcl();
				printf("Goodbye\n");
				exit(0);
				break;
			case 1:
				ttltbr("Text TL to BR");
				break;
			case 2:
				bounc("Text Bounce - bounces kind of like a ball");
				break;
			case 3:
				bubl("Building Characters - can be as BIG as you want. Say hi!");
				break;
			case 4:
				stripe("Striped downwards - pretty cool huh", 3);
				break;
			default:
				printf("\nNo such valid option!\n");
				sleep(1);
				break;
		}
	}
	return 0;
};
