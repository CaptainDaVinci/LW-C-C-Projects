#include "play.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
// #include "stuff.h"

// colours
#define RESET  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


static void setColour(Game *game);
static void calculateScore(char *word, char *input, Game *game);

void settings(Game *game)			// get user to chose settings
{
	int option = -1;
	srand((unsigned)time(NULL)); // set the seed for random number generation

	stcl();
	while(true)
	{
		stcl();

		printf("\nType the number of the setting you want to configure\n\n");
		printf("1. Colour [%i]\n", game->colour);
		printf("2. Animation [%i]\n", game->animate);
		printf("> ");

		scanf("%i", &option);

		switch(option)
		{

			case 1:	game->colour = !game->colour;
					break;

			case 2: game->animate = !game->animate;
					break;

			case 3: stcl();
					return;

			default: printf("\nInvalid!\n");
					 break;
		}
	}
}

//play game
void play(Game *game)
{
	int i;

	// countdown
	for(i = 5; i > 0; i--)
	{
		stcl();
		printf("Game Starts in... %d\n", i);
		sleep(1);
	}
	stcl();

	char *words[400] = {"Words","Legendary","Jokes! I'm sorry, I didn't mean it that way",
	    "Complexity is good","Overload! Oh no it's gonna collapse!!!","ItzPvpz",
		"That is good!","core()","HOW?! Please tell me...", "gg guys, gg!",
		"Why did you do that?!", "Stop it! Your being mean now.", "Unfortunately he turned round and saw me...",
		"This isn't going well. AT ALL!", "I rate this game a 10/10", "STOP NOW!", "I lOvE tHiS gAmE!",
		"I am having a great time!", "Linux is the best operating system ever!",
		"Apple sucks, windows is okay, and linux is BAE!","There are exploding particles in my game",
		"Splash text lol.", "What do you not understand?", "<3 you", "a usb, a disk, a brain",
		"That is a bad teacher, for sure!", "Typing typing typing", "Don't judge me by what I just did.",
		"public class Core(){public static void main(String[] args){System.out.println(\"Hello World!\");}}",
		"Absolutely!", "What are you doing here?", "Not now", "Are you a programmer?", "Yes. I think",
		"Don't judge me by what I just did.", "Is that actually all you got?",
		"Bruh", "I SAID NOT NOW!", "caps. NON-CAPS", "I don't think you realise how many lines of code there is."}; // list of words


	game->streak = 8;
	while(true)
	{
		stcl();

		char input[400];
		int w = rand() / (RAND_MAX / 38 + 1); // word set to random number to chose a random word from words[]
		printf("w = %d\n", w);
		setColour(game);

		printf("\tType .E to exit\n");
		printf("=========Score: [%i]    Total: [%i] ==============\n", game->score, game->td);
		printf("=========Correct: [%i]    Streak: [%i] ==============\n", game->cor, game->streak);
		printf("\t%s\n", words[w]);
		printf("\n\n[>   ");
		scanf(" %[^\n]s", input);

		if(!strcmp(input, ".E"))			// strcmp of two string will return 0 if they are the same
		{									// !(strcmp) will complement that and return 'true'.
			printf("\nGAME EXITED!\n");
			break;
		}

		calculateScore(input, words[w], game);

		if((game->streak % 10 == 0) && game->animate && game->streak)	// if streak is multiple of 10 and not 0
			anicel(game->streak);

		game->td++;
	}
}

void setColour(Game *game)
{
	if((game->streak > 9) && (game->streak < 101))
		printf("%s", KBLU);

	else if((game->streak > 100) && (game->streak < 1001))
		printf("%s", KGRN);

	else if((game->streak > 1001))
		printf("%s", KYEL);

	if(!game->colour)
		printf("%s", RESET);
}

void calculateScore(char *word, char *input, Game *game)
{
	if(!strcmp(input, word))
	{
		game->score++;
		game->cor++;
		game->streak++;

		if((game->streak > 10) && (game->streak < 101))
			game->score += 2;

		if((game->streak > 100) && (game->streak < 1001))
			game->score += 5;

		if((game->streak > 1000) && (game->streak < 10001))
			game->score += 10;
	}

	else
	{
		game->score--;
		game->streak = 0;
		printf("%s", RESET);				// if streak breaks, then reset colour.
	}
}
