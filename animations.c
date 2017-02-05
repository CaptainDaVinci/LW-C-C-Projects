#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "animations.h"

void stcl(){
	system("clear"); // change clear to cls if your on windows
}

#define NELEMS(x) (sizeof(x) / sizeof(x[0]))
int los(char *s){
	int i = 0;
	while(*s++) i++;
	return i;
}

void ttltbr(char text[40]){
	
	//text position
	int tx = 0;
	int ty = 0;
	
	//loop for 40 times
	int a;
	const int TOTAL = 20;
	for(a = 0; a < 20; a++){ // frame loop
		//positioning
		ty = a;
		tx++;
		//printing
		stcl();
		printf("=================================================\n");
		int e = 0;
		while(e < ty){ // before whitespace
			printf(" \n");
			e++;
		}
		int b = 0;
		while(b < tx){
			printf(" ");
			b++;
		}
		printf("%s\n", text);
		while(e < TOTAL){ // after whitespace
			printf("\n");
			e++;
		}
		printf("=================================================\n");
		usleep(100000);
		
	}
	stcl();
}


/* The map tack tick used in this animation
 * is something i will be doing much more often
 * 
 * each frame has a number (a) and when run,
 * the a of ymap sets the ty (text y position)
 * which then produces that amount of new lines
 * which gives it the effect of being further down
 * 
 * for more information - email: [BLOCKED]
 */
void bounc(char text[]){
	stcl();
	int ty = 1;
	const int ymap[30] /*30 long*/ = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 8, 9, 10, 11, 10, 9, 10, 11, 11, 11, 11, 11, 11, 11, 11}; // map of y position
	const int maplen = 30;
	const int longdist = 11; // longest distance in the map
	int a;
	for(int a = 0; a < maplen; a++){ // frame loop
		ty = ymap[a];
		int b = 0;
		while(b < ty){
			printf("\n");
			b++;
		}
		printf("%s\n", text);
		while(b < longdist){
			printf("\n");
			b++;
		}
		char *text2 = text;
		int h;
		for( h = 0 ; h < los(text2); h++){
			printf("#");
		}
		printf("\n");
		usleep(50000);
		stcl();
	}
	stcl();
}

void bubl(char text[]){
	stcl();
	int a;
	char *text2 = text; // stops compile errors
	int noe = los(text2); // number of elements
	printf("\nnoe is %i\n", noe);
	int TOTALFRAMES1 = noe /*chars in text*/ + 10 /*movement*/; // 17 total frames
	for(a = 0; a < TOTALFRAMES1; a++){ // frame loop
		if(a < (noe + 1)){
			int b;
			for(b = 0; b < a; b++){
				char cc = text[b];
				printf("%c", cc);
			}
			printf("\n");
		}else{
			int d = a - noe;
			int e;
			for(e = 0; e < d; e++){
				printf("\n");
			}
			printf("%s\n", text);
		}
		usleep(50000);
		stcl();
	}
	int f;
	for(f = noe; f > -1; f--){
		printf("\n\n\n\n\n\n\n\n\n\n");
		int g;
			for(g = 0; g < f; g++){
				char cc2 = text[g];
				printf("%c", cc2);
			}
			printf("\n");
		usleep(50000);
		stcl();
	}
}

void stripe(char text[], int times){
	stcl();
	int a;
	for(a = 0; a < times; a++){ // loop for repeating it an amount of times
		int b;
		for(b = 0; b < 5; b++){ // b stripe
			stcl();
			int c;
			for(c = 0; c < b; c++){ // before text
				printf("%s\n", text);
			}
			printf("\n");
			while(c < 5){
				printf("%s\n", text);
				c++;
			}
			usleep(100000);
		}
	}
}
