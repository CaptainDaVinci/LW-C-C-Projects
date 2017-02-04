#include "play.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "stuff.h"

bool hsbu = false; //has settings been used
int gs = 42;
void settings(){ // get user to chose settings
	stcl();
	int optid1 = -1;
	while(true){
		printf("\nType the number of the setting you want to configure\nType -1 to exit\n\n");
		/*printf("1) [%i] Sentences\n", sentences);
		printf("2) [%i] Store High Score\n", stohs);*/
		printf("1) [%i] Seed\n", gs);
		printf("> ");
		scanf("%i", &optid1);
		printf("\n");
		switch(optid1){
			case -1:
				printf("\n\nExiting settings...\n\n");
				stcl();
				return;
			/*case 1:
				if(sentences == 0){
					sentences = 1;
				}else{
					sentences = 0;
				}
				break;
			case 2:
				if(stohs == 0){
					stohs = 1;
				}else{
					stohs = 0;
				}
				break;*/
			case 1:
				printf("\n\nSeed current value: %i\n\nNew Value> ", &gs);
				scanf("%i", &gs);
				break;
			default:
				printf("\nInvalid!\n");
				stcl();
				break;
		}
	}
}
int sentences = 0; // sentences or words
int stohs = 0; //store high score


//play game
int score;
void play(){
	score = 0;
	stcl();                                       //countdown
	printf("Game Starts in... 5\n");             //countdown
	sleep(1);                                   //countdown
	stcl();                                    //countdown
	printf("Game Starts in... 4\n");          //countdown
	sleep(1);                                //countdown
	stcl();                                 //countdown
	printf("Game Starts in... 3\n");       //countdown
	sleep(1);                             //countdown
	stcl();                              //countdown
	printf("Game Starts in... 2\n");    //countdown
	sleep(1);                          //countdown
	stcl();                           //countdown
	printf("Game Starts in... 1\n"); //countdown
	sleep(1);
	stcl();
	char *words[400] = {"Words","Legendary","Jokes","h67dF45de","Overload","ItzPvpz","That is good!","core()","@[42#] 05gth68e3dse",
		"gg guys, gg!", "Why did you do that?!", "Stop it!", "Unfortunately he turned round and saw me...", "This isn't going well. AT ALL!",
		"I rate this game a 10/10", "STOP NOW!", "I lOvE tHiS gAmE!"
	}; // list of words
	srand(gs); // set the seed for random number generation
	while(true){
		stcl();
		char inp[400];
		int w = rannum(0,16); // word set to random number to chose a random word from words[]
		printf("   Type .E to exit\n===============Score: [%i]===================\n", score);
		printf("   %s\n", words[w]);
		printf("\n\n\n[>   ");
		scanf(" %[^\n]%*c", &inp);
		if(strequ(inp, ".E")){
			printf("\n\nGAME EXITED!\n\n");
			break;
		}
		if(strequ(inp, words[w])){
			score++;
		}else{
			score--;
		}
	}
}
