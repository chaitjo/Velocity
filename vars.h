//Header file containing global variables and structure definitions for the player and enemies.

#ifndef __GAME_VARIABLES_H_INCLUDED__
#define __GAME_VARIABLES_H_INCLUDED__

int speed= 30;		//Global variable for speed at which the player plays the game.
char scr[1000];		//Global score variable.

//Data structure for player infomation.
struct pl
{
	int width;
	int height;
	int pos;
	char name[10];
	int score;
} player;

//Data structure for barriers, aka 'enemies'.
struct en
{
	int height;
	int height2;
	int pos;
	int pos2;
	int pos3;
} enemy;

enum POS { LEFT= -1, CENTER= 0, RIGHT= 1 } ;	//Notations to define player's position.

#endif
