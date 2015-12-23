#include <conio.h>		//Provides console input/output functions.
#include <stdio.h>		//Provides streams to operate with keyboard.

#include "scores.h"		//Contains function definitions for appending to/diplaying a highscores database.
#include "gfx.h"		//Contains function definitions to generate the game environment.
#include "vars.h"		//Contains global variables and structure definitions for the player and enemies.

void main()
{
	clrscr();

	//Initializing graphics.
	setviewport(0, 0, 200, getmaxy(), 0);
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");

	//Initializing player variables.
	int pos= CENTER;
	player.width= 20;
	player.height= 40;
	player.score= 0;

	//Initializing enemy variables.
	enemy.height= 0;
	enemy.height2= 200;
	enemy.pos= LEFT;
	enemy.pos2= CENTER;
	enemy.pos3= RIGHT;

	char input= menu();		//Displays the menu with instructions to play the game or quit the program (if return value of menu() is 'q').
	int start= clock();		//Assigns the current processor time to the integer start. Used in the score() function.

	//Start of main game loop.
	while(input!= 'q')
	{
		score(start);

		if(kbhit())	
		{
			input= getch();

			switch(input)
			{
				//'a' to move vehicle to left.
				case 'a':		
				{
					pos--;
					if(pos< -1)
						   pos= -1;
					
					cleardevice();
					pGen(pos);
					eGen(enemy.pos, enemy.pos2, enemy.pos3, enemy.height, enemy.height2);
					lineGen(pos);
					
					delay(10);
					break;
				}

				//'d' to move vehicle to right.
				case 'd':		
				{
					pos++;
					if(pos> 1)
						   pos= 1;
					
					cleardevice();
					pGen(pos);
					eGen(enemy.pos, enemy.pos2, enemy.pos3, enemy.height, enemy.height2);
					lineGen(pos);
					
					delay(10);
					break;
				}
			}
		}

		else
		{
			cleardevice();
			pGen(pos);
			eGen(enemy.pos, enemy.pos2, enemy.pos3, enemy.height, enemy.height2);
			lineGen(pos);
			delay(speed);		//Determines the game speed after every refresh.
		}

		if( checkCrash(player.pos, 400-player.height, enemy.pos, enemy.pos2, enemy.pos3, enemy.height, enemy.height2) == 1)
		{
			//This section is only invoked if the player crashes.
			cleardevice();
			settextstyle(0, 0, 6);
			outtextxy(100, getmaxy()/2-100, "GAME OVER!");

			settextstyle(9, 0, 4);
			outtextxy(150, getmaxy()/2, "Your Score");
			outtextxy(475, getmaxy()/2, scr);
			getch();

			clrscr();
			cleardevice();
			cout<<"Enter your name..."<<endl;
			cin>>player.name;

			//This section adds player's data to the highscores file and subsequently displays them.
			clrscr();
			cleardevice();
			insert(player);
			displayScores();
			getch();
			cleardevice();

			//This section resets the score and brings the player back to the main menu.
			delay(1000);
			input= menu();
			start= clock();
			speed= 30;
		}
	}

	closegraph();
}
