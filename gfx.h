//Header file containing function definitions to generate the game environment.

#ifndef __GAME_FUNCTIONS_H_INCLUDED__
#define __GAME_FUNCTIONS_H_INCLUDED__

#include <stdlib.h>			//Standard general utilities library, including randomization functions.
#include <graphics.h>		//Used to draw shapes and colours on screen.
#include <dos.h>			//Handles interuptions and generates delays.
#include <time.h>			//Functions to get and manipulate time infomation, used for randomization.

#include "vars.h"			//Contains global variables and structure definitions for the player and enemies.

//Function to check if the player's vehicle has crashed with an enemy.
int checkCrash(int px, int py, int ex1, int ex2, int ex3, int ey, int ey2)
{
	int check= 0;
	if ((py== ey && (ex1== px-15 || ex2== px-15)) || (py== ey2 && ex3== px-15) )
		check= 1;

	return check;
}

//Function to display and enumerate the score.
void score(int start)				
{
	sprintf(scr, "%d", (clock()-start)/10);
	
	char spd [10];
	sprintf(spd, "%d", speed);
	outtextxy(getmaxx()-100, 150, spd);

	settextstyle(10, 0, 4);
	outtextxy(getmaxx()-100, 50, scr);

	player.score= (clock()-start)/10;
		
	//This section of code increases game speed after a certain score is attained.
	if(player.score>= 25) {
		speed= 25;
		if(player.score>= 50) {
			speed= 20;
			if(player.score>= 75) {
				speed= 15;
				if(player.score>= 100) {
					speed= 10;
					if(player.score>= 150) {
						speed= 7;
	} } } } }	//Oh God why...

	/*WHY DOES THIS NOT WORK?!?!?!
	if(player.score>= 25 && player.score%25== 0 && speed>= 10 && flag == 0)
		speed= speed-5; */

	delay(10);
}

//Function to create the main menu which flashes before every attempt.
char menu()					
{
	cleardevice();
	setcolor(WHITE);

	settextstyle(9, 0, 8);
	outtextxy(20, getmaxy()/2-210, "VELOCITY");

	settextstyle(0, 0, 0);
	outtextxy(120, getmaxy()/2-50, "A game by Chaitanya Joshi & Rachitesh Kumar");

	settextstyle(0, 0, 2);
	outtextxy(120, getmaxy()/2+50, "Press any key to Play");
	outtextxy(150, getmaxy()/2+100, "Press 'q' to Quit");

	settextstyle(0, 0, 1);
	outtextxy(20, getmaxy()/2+200, "Press 'a' to move left and 'd' to move right. Avoid the road-blocks!");

	delay(1500);
	char key= getch();
	return key;
}

//Function to generate the player vehicle on the screen.
void pGen(int &pPos)			
{
	if(pPos== LEFT)
		player.pos= 115;
	else if(pPos== CENTER)
		player.pos= 145;
	else if(pPos== RIGHT)
		player.pos= 175;

	setlinestyle(SOLID_LINE, 0, 2);

	rectangle(player.pos-player.width/2, 400-player.height, player.pos+player.width/2, 400);
	rectangle(player.pos-player.width/2, 375, player.pos+player.width/2, 385);
	arc(player.pos-6, 360, 180, 360, 2);
	arc(player.pos+6, 360, 180, 360, 2);
	line(player.pos-6, 375, player.pos-2, 360);
	line(player.pos+6, 375, player.pos+2, 360);
	line(player.pos-2, 400, player.pos-2, 385);
	line(player.pos+2, 400, player.pos+2, 385);

	int points1[]= {player.pos-2, 360, player.pos+2, 360, player.pos+6, 375, player.pos-6, 375};
	int points2[]= {player.pos+2, 385, player.pos+2, 400, player.pos-2, 400, player.pos-2, 385};
	int points3[]= {player.pos+player.width/2, 375, player.pos+player.width/2, 385, player.pos-player.width/2, 385, player.pos-player.width/2, 375};

	setfillstyle(SOLID_FILL,RED);
	fillpoly(4, points1);
	fillpoly(4, points2);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	fillpoly(4, points3);
}

//Function to generate barriers, aka 'enemies'.
void eGen(int &ePos, int &e2, int &e3, int &eH, int &eH2)		
{
	setcolor(YELLOW);
	setfillstyle(BKSLASH_FILL,YELLOW);

	if(ePos== -1)
		ePos= 100;
	else if(ePos== 0)
		ePos= 130;
	else if(ePos== 1)
		ePos= 160;

	if(e2== -1)
		e2= 100;
	else if(e2== 0)
		e2= 130;
	else if(e2== 1)
		e2= 160;

	if(e3== -1)
		e3= 100;
	else if(e3== 0)
		e3= 130;
	else if(e3== 1)
		e3= 160;

	//This section of code randomizes the re-generation of an enemy once it has been crossed. 
	if(eH>= 450)			
	{
		eH= 20;
		srand(time(NULL));
		ePos= rand()%3 -1;
		srand(time(NULL)-11);
		e2=rand()%3 -1;
	}

	if(eH2>= 450)
	{
		eH2= 20;
		srand(time(NULL)-23);
		e3=rand()%3 -1;
	}

	bar(ePos, eH, ePos+30, eH+5);
	bar(e2, eH, e2+30, eH+5);
	bar(e3, eH2, e3+30, eH2+5);

	eH+= 10;
	eH2+= 10;
}

//Function to generate the rest of the game environment.
void lineGen(int pos)				
{
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 20);
	line(100, getmaxy(), 100, 0);
	line(130, getmaxy(), 130, 0);
	line(160, getmaxy(), 160, 0);
	line(190, getmaxy(), 190, 0);
	setlinestyle(DASHED_LINE, 0, 2);
	line(115, 360, 115, 0);
	line(145, 360, 145, 0);
	line(175, 360, 175, 0);
	line(115, getmaxy(), 115, 400);
	line(145, getmaxy(), 145, 400);
	line(175, getmaxy(), 175, 400);

	if(pos== -1)
	{
		line(145, 360, 145, 400);
		line(175, 360, 175, 400);
	}
	else if(pos== 0)
	{
		line(115, 360, 115, 400);
		line(175, 360, 175, 400);
	}
	else if(pos== 1)
	{
		line(145, 360, 145, 400);
		line(115, 360, 115, 400);
	}
}

#endif
