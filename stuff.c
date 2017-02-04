#include "stuff.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

bool strequ(char text1[], char text2[]){
	/*char c1ch;
	char c2ch;
	int a = 0;
	while(c1ch != '\0'){
		c1ch = text1[a];
		c2ch = text2[a];
		if(c1ch != c2ch){
			return false;
		}
		a++;
	}
	return true;*/
	if(strcmp(text1, text2) == 0){
		return true;
	}else{
		return false;
	}
}
void stcl();
void stcl(){
	system("clear"); // change clear to cls if your on windows
}

int rannum(int min_num, int max_num){
	long long int result=0,low_num=0,hi_num=0;
	if(min_num<max_num){
		low_num=min_num;
		hi_num=max_num+1; // this is done to include max_num in output.
	}else{
		low_num=max_num+1;// this is done to include max_num in output.
		hi_num=min_num;
	}
	
	result = ((rand())%(hi_num-low_num))+low_num;
	return result;
}
