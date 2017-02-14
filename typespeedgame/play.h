#ifndef __TYPING_H__
#define __TYPING_H__

#include <stdbool.h>

typedef struct
{
	bool colour, animate;
	int score, streak, cor, td, i;

}Game;

Game *game;

void play(Game *);
void settings(Game *);
void stcl(void);                            // clear screen
int rannum(int min_num, int max_num);       // generate a random number
void anicel(int streak);                    // animation for celebration :)

#endif
