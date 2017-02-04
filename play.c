#include "play.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "stuff.h"

bool hsbu = false; //has settings been used
int gs = 42; // seed
int sentences = 0; // sentences or words
int stohs = 0; //store high score
int usecol = 1; // wether colours are used or not
void settings(){ // get user to chose settings
	stcl();
	int optid1 = -1;
	while(true){
		stcl();
		printf("\nType the number of the setting you want to configure\nType -1 to exit\n\n");
		/*printf("1) [%i] Sentences\n", sentences);
		printf("2) [%i] Store High Score\n", stohs);*/
		printf("1) [%i] Seed\n", gs);
		printf("2) [%i] Use Colours\n", usecol);
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
			case 2:
				if(usecol == 0){
					usecol = 1;
				}else{
					usecol = 0;
				}
				break;
			default:
				printf("\nInvalid!\n");
				stcl();
				break;
		}
	}
}


// colours
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

//play game
int score; // the score (durr)
int td; // total done
int cor; // total correct
int streak; // correct streak
void play(){
	score = 0;
	td = 0;
	cor = 0;
	streak = 0;
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
	char *words[400] = {"Words","Legendary","Jokes! I'm sorry, I didn't mean it that way","Complexity is good","Overload! Oh no it's gonna collapse!!!","ItzPvpz",
		"That is good!","core()","HOW?! Please tell me...",
		"gg guys, gg!", "Why did you do that?!", "Stop it! Your being mean now.", "Unfortunately he turned round and saw me...", "This isn't going well. AT ALL!",
		"I rate this game a 10/10", "STOP NOW!", "I lOvE tHiS gAmE!", "I am having a great time!", "Linux is the best operating system ever!",
		"Apple sucks, windows is okay, and linux is BAE!","There are exploding particles in my game", "Splash text lol.", "What do you not understand?",
		"That is a bad teacher, for sure!", "Typing typing typing","public class Core(){public static void main(String[] args){System.out.println(\"Hello World!\");}}",
		"Absolutely!", "What are you doing here?", "Not now", "Are you a programmer?", "Yes. I think", "Don't judge me by what I just did.", "<3 you", "a usb, a disk, a brain", "Is that actually all you got?", "Bruh", "I SAID NOT NOW!", "caps. NON-CAPS", "I don't think you realise how many lines of code their is."
	}; // list of words
	srand(gs); // set the seed for random number generation
	while(true){
		stcl();
		char inp[400];
		int w = rannum(0,38); // word set to random number to chose a random word from words[]
		if((streak > 10) && (streak < 101)){
			printf("%s", KBLU);
		}
		if((streak > 100) && (streak < 1001)){
			printf("%s", KGRN);
		}
		if((streak > 1000) && (streak < 10001)){
			printf("%s", KYEL);
		}
		if(usecol == 0){
			printf("%s", KNRM);
		}
		printf("   Type .E to exit\n=========Score: [%i]    Total: [%i] ==============\n", score, td);
		printf("=========Correct: [%i]    Streak: [%i] ==============\n", cor, streak);
		printf("   %s\n", words[w]);
		printf("\n\n\n[>   ");
		scanf(" %[^\n]%*c", &inp);
		if(strequ(inp, ".E")){
			printf("\n\nGAME EXITED!\n\n");
			break;
		}
		if(strequ(inp, words[w])){
			score++;
			cor++;
			streak++;
			if((streak > 10) && (streak < 101)){
				score++;
			}
			if((streak > 100) && (streak < 1001)){
				score++;
				score++;
				score++;
			}
			if((streak > 1000) && (streak < 10001)){
				score++;
				score++;
				score++;
				score++;
				score++;
				score++;
				score++;
			}
		}else{
			score--;
			streak = 0;
		}
		td++;
	}
}
