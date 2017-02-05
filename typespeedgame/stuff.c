#include "stuff.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

void stcl();
bool strequ(char text1[], char text2[]){
	if(strcmp(text1, text2) == 0){
		return true;
	}else{
		return false;
	}
}
void stcl(){
	system("clear"); // change clear to cls if your on windows
}

int rannum(int min_num, int max_num){
	long long int result = 0, low_num = 0, hi_num = 0;

	if(min_num < max_num){
		low_num = min_num;
		hi_num = max_num+1; // this is done to include max_num in output.
	}else{
		low_num = max_num+1;// this is done to include max_num in output.
		hi_num = min_num;
	}

	result = ((rand())%(hi_num-low_num))+low_num;
	return result;
}

void anicel(char text[50]){

	//text position
	int tx = 0;
	int ty = 0;

	//loop for 40 times
	int a;
	for(a = 0; a < 20; a++){
		//positioning
		ty = a;
		tx++;
		//printing
		stcl();
		printf("=========================================\n");
		int e = 0;
		while(e < ty){
			printf(" \n");
			e++;
		}
		int b = 0;
		while(b < tx){
			printf(" ");
			b++;
		}
		printf("%s\n", text);
		printf("=========================================\n");
		usleep(100000);

	}
	stcl();
}
